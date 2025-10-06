#include "sim.h"

#define SCALE_FACTOR 8
#define HEIGHT (SIM_Y_SIZE / SCALE_FACTOR)
#define WIDTH (SIM_X_SIZE / SCALE_FACTOR)
#define SPAWN_CHANCE 10
#define BAD_CHANCE 50
#define GOOD_COLOR 0xFF00
#define BAD_COLOR 0xFF0000

static void draw_generation(unsigned *generation) {
    for (unsigned x = 0; x < WIDTH; ++x) {
        for (unsigned y = 0; y < HEIGHT; ++y) {
            int argb = generation[(y + 1) * (WIDTH + 2) + (x + 1)];
            for (unsigned i = 0; i < SCALE_FACTOR; ++i) {
                for (unsigned j = 0; j < SCALE_FACTOR; ++j) {
                    simPutPixel(x * SCALE_FACTOR + i, y * SCALE_FACTOR + j, argb);
                }
            }
        }
    }
    simFlush();
}

static void instantiate_population(unsigned *generation) {
    for (unsigned row = 1; row <= HEIGHT; row++) {
        for (unsigned col = 1; col <= WIDTH; col++) {
            generation[row * (WIDTH + 2) + col] = ((simRand() % SPAWN_CHANCE) == 0)
                                                      ? ((simRand() % BAD_CHANCE) == 0 ? BAD_COLOR : GOOD_COLOR)
                                                      : 0;
        }
    }
}

void app() {
    unsigned generations[2][(HEIGHT + 2) * (WIDTH + 2)] = {0};

    int t = 0;

    instantiate_population(generations[t]);

    while (1) {
        draw_generation(generations[t]);
        for (unsigned y = 1; y <= HEIGHT; y++) {
            for (unsigned x = 1; x <= WIDTH; x++) {
                unsigned neighbour_cnt = 0;
                unsigned has_red_neighbour = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (i == 0 && j == 0) continue;
                        neighbour_cnt += generations[t][(y + i) * (WIDTH + 2) + (x + j)] != 0 ? 1 : 0;
                        has_red_neighbour |= (generations[t][(y + i) * (WIDTH + 2) + (x + j)] == BAD_COLOR ? 1 : 0);
                    }
                }

                unsigned idx = y * (WIDTH + 2) + x;
                generations[(t + 1) & 1][idx] = (neighbour_cnt == 3 ||
                                                 (generations[t][idx] && neighbour_cnt == 2))
                                                    ? (has_red_neighbour ? BAD_COLOR : GOOD_COLOR)
                                                    : 0;
            }
        }

        t = (t + 1) & 1;
    }
}
