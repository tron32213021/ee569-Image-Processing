#pragma once
#include "uni.h"
void showGrayImage(const u8* image, int height, int width, const char* winName = "Win");
void showRGBImage(const u8* image, int height, int width, const char* winName = "Win");
u8* createHistImage(const u32* hist, int height, int width);
