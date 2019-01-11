#pragma once
#include "uni.h"
unsigned char* readImage(const char* fileName, int size);
void writeImage(const char* fileName, u8* image, int size);
void printImageData(const u8* image, int size);
u8* getChannel(const u8* image, int height, int width, int channel);
unsigned char* demosaicing(u8* image, int height, int width, const char* type = "bilinear");
u32* calculate_hist(u8* image, int height, int width);
u8* getTransferMap(u32* hist, int height, int width);
u8* transferImageByMap(u8* map, u8* image, int height, int width);
u8* enhanceImageByHist(u8* image, u32* hist, int height, int width);
u8* enhanceImageByCumulative(u8* image, u32* hist, int height, int width);