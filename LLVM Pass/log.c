#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 8192
static int cur_size = 0;
static char* arr[BUFF_SIZE][2];

void TraceLogger(char *funcName, char *funcUse) {
    if (cur_size == BUFF_SIZE) {
        // Set larger buffer for stdout to reduce write syscalls
        static char stdout_buffer[8192];
        setvbuf(stdout, stdout_buffer, _IOFBF, sizeof(stdout_buffer));
        
        for (int i = 0; i < BUFF_SIZE; ++i) {
            printf("%s <-- %s\n", arr[i][0], arr[i][1]);
        }
        fflush(stdout);  // Ensure all output is written
        
        cur_size = 0;
    } else {
        arr[cur_size][0] = funcName;
        arr[cur_size][1] = funcUse;
        ++cur_size;
    }
}