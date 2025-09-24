#pragma once
#define SIM_X_SIZE 2048
#define SIM_Y_SIZE 1024

#ifndef __sim__
void simInit();
void app();
void simExit();
void simFlush();
void simPutPixel(int x, int y, int argb);
int simRand();
#endif