/*
copyright: Zhenye Jiang
Name:	Zhenye Jiang
USC_ID:	5553039273
Email:	zhenyeji@usc.edu
Submission date: Jan 22 2019
*/
#include <opencv2/opencv.hpp>
#include "showImage.h"
#include "myLib.h"
void showGrayImage(const u8* image, int height, int width,const char* winName)
{
	cv::Mat myMat(height, width, CV_8UC1, (void *)image);
	cv::imshow(winName, myMat);
	cv::waitKey(0);
	writeImage(winName, image, height*width);
}

void showRGBImage(const u8* image, int height, int width,const char* winName)
{
	cv::Mat myMat(height, width, CV_8UC3, (void *)image);
	cv::Mat dst;
	cv::cvtColor(myMat, dst, cv::COLOR_RGB2BGR);
	cv::imshow(winName, dst);
	cv::waitKey(0);
	writeImage(winName, image, height*width*3);
}
void fillBar(u8* canvas, int height,int width,int x1, int y1, int x2, int y2)
{
	for (int i = x1; i < x2; ++i)
		for (int j = y1; j < y2; ++j)
			canvas[i*width + j] = 255;
}
u8* createHistImage(const u32* hist, int height, int width)
{
	double bar_width = width / 256.0;
	u32 max = 0;
	for (int i = 0; i < 256; ++i)
		if (max < hist[i])
			max = hist[i];
	double bar_unit = height * 0.95 / max;
	u8* canvas = new u8[height*width];
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			canvas[i*width + j] = 0;

	for (int i = 0; i < 256; ++i)
		fillBar(canvas, height, width, height - bar_unit * hist[i], i*bar_width, height, (i + 1)*bar_width);
	return canvas;
}
