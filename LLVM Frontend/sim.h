#pragma once
#define SIM_X_SIZE 512
#define SIM_Y_SIZE 256

#ifndef __icd10b69__
void flush();
void putPixel(int x, int y, int argb);
int randMod(int m);
#endif

void simInit();
void app();
void simExit();
