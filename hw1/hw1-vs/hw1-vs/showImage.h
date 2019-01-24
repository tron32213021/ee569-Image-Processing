/*
copyright: Zhenye Jiang
Name:	Zhenye Jiang
USC_ID:	5553039273
Email:	zhenyeji@usc.edu
Submission date: Jan 22 2019
*/
#pragma once
#include "uni.h"
void showGrayImage(const u8* image, int height, int width, const char* winName );
void showRGBImage(const u8* image, int height, int width, const char* winName );
u8* createHistImage(const u32* hist, int height, int width);
