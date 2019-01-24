/*
copyright: Zhenye Jiang
Name:	Zhenye Jiang
USC_ID:	5553039273
Email:	zhenyeji@usc.edu
Submission date: Jan 22 2019
*/
#pragma once
#include "uni.h"

class ImagePixelGetter
{
private:
	int height, width,channel;
	u8* image;
public:
	ImagePixelGetter(u8* image, int height, int width,int channel=1);
	u8 get(int x, int y,int z=0);
};
void printu32Number(u32* hist, int n);
void printu8Number(u8* map, int n);
u8* readImage(const char* fileName, int size);
void writeImage(const char* fileName, const u8* image, int size);
void printImageData(const u8* image, int size);
u8* getChannel(const u8* image, int height, int width, int channel);
unsigned char* demosaicing(u8* image, int height, int width, const char* type = "bilinear");
u32* calculate_hist(u8* image, int height, int width);
u8* getTransferMap(u32* hist, int height, int width);
u8* transferImageByMap(u8* map, u8* image, int height, int width);
u8* enhanceImageByHist(u8* image, u32* hist, int height, int width);
u8* enhanceImageByCumulative(u8* image, u32* hist, int height, int width);
u8* weightedMeanFilter(u8* image, int height, int width, int N, const char* method = "uniform");
double calcPSNR(u8* Y, u8* I, int height, int width);
u8* removeMixNoise(u8* image, int height, int width, int channel);
u8* removeShotNoise(u8* image, int height, int width);