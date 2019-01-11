#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include <string.h>

u8* readImage(const char* fileName, int size)
{
	FILE* file;
	u8* image = new u8[size];
	if (!(file = fopen(fileName, "rb")))
	{
		printf("Cannot open file: %s\n", fileName);
		exit(1);
	}
	fread(image, sizeof(u8), size, file);
	fclose(file);
	return image;
}

void writeImage(const char* fileName, u8* image,int size)
{
	FILE* file;
	if (!(file = fopen(fileName, "wb")))
	{
		printf("Cannot open file: %s\n", fileName);
		exit(1);
	}
	fwrite(image, sizeof(u8), size, file);
	fclose(file);
}

void printImageData(const u8* image, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", image[i]);
	printf("\n");
}

u8* getChannel(const u8* image, int height, int width, int channel)
{
	u8* newImage = new u8[height*width];
	int imageSize = width * height;
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			newImage[i*width + j] = image[(i*width + j)*3+channel];
	return newImage;
}

u8* demosaicing(u8* image, int height, int width, const char* type)
{
	u8* newImage = new u8[height*width * 3];
	double alpha = 1.0 / 2, beta = 5.0 / 8, gamma = 3.0 / 4;
	int imageSize = height * width;
	int r = 0;
	int g = 1;
	int b = 2;
	int x, y;
	int center, left, right, top, bot, left_top, left_bot, right_top, right_bot, top2, bot2, left2, right2;
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			center = width * i + j;
			//left
			x = i, y = j - 1;
			if (y < 0)
				y = 2 * j - y;
			left = width * x + y;
			//right
			x = i, y = j + 1;
			if (y >= width)
				y = 2 * j - y;
			right = width * x + y;
			//top
			x = i - 1, y = j;
			if (x < 0)
				x = 2 * i - x;
			top = width * x + y;
			//bot
			x = i + 1, y = j;
			if (x >= height)
				x = 2 * i - x;
			bot = width * x + y;
			//left2
			x = i, y = j - 2;
			if (y < 0)
				y = 2 * j - y;
			left2 = width * x + y;
			//right2
			x = i, y = j + 2;
			if (y >= width)
				y = 2 * j - y;
			right2 = width * x + y;
			//top2
			x = i - 2, y = j;
			if (x < 0)
				x = 2 * i - x;
			top2 = width * x + y;
			//bot2
			x = i + 2, y = j;
			if (x >= height)
				x = 2 * i - x;
			bot2 = width * x + y;
			//left_top
			x = i - 1, y = j - 1;
			if (x < 0)
				x = 2 * i - x;
			if (y < 0)
				y = 2 * j - y;
			left_top = width * x + y;
			//left_bot
			x = i + 1, y = j - 1;
			if (x >= height)
				x = 2 * i - x;
			if (y < 0)
				y = 2 * j - y;
			left_bot = width * x + y;
			//right_top
			x = i - 1, y = j + 1;
			if (x < 0)
				x = 2 * i - x;
			if (y >= width)
				y = 2 * j - y;
			right_top = width * x + y;
			//right_bot
			x = i + 1, y = j + 1;
			if (x >= height)
				x = 2 * i - x;
			if (y >= width)
				y = 2 * j - y;
			right_bot = width * x + y;
			///////////////////////////////////////
			int red_pos = center * 3 + r;
			int green_pos = center * 3 + g;
			int blue_pos = center * 3 + b;

			if (i % 2 == j % 2) //on green pixel
			{

				//set green pixel value
				newImage[green_pos] = image[center];

				if (i % 2 == 0)
				{
					//set red pixel value
					newImage[red_pos] = (image[right] + image[left]) / 2;
					if (strcmp(type, "MHC") == 0)
						newImage[red_pos] += beta * (image[center] - 0.2*(image[left2] + image[right2] + image[left_top] + image[left_bot] + image[right_top] + image[right_bot]) + 0.1*(image[top2] + image[bot2]));
					//set blue pixel value
					newImage[blue_pos] = (image[bot] + image[top]) / 2;
					if (strcmp(type, "MHC") == 0)
						newImage[blue_pos] += beta * (image[center] - 0.2*(image[top2] + image[bot2] + image[left_top] + image[left_bot] + image[right_top] + image[right_bot]) + 0.1*(image[left2] + image[right2]));
				}
				else
				{
					//set red pixel value
					newImage[red_pos] = (image[top] + image[bot]) / 2;
					if (strcmp(type, "MHC") == 0)
						newImage[red_pos] += beta * (image[center] - 0.2*(image[top2] + image[bot2] + image[left_top] + image[left_bot] + image[right_top] + image[right_bot]) + 0.1*(image[left2] + image[right2]));
					//set blue pixel value
					newImage[blue_pos] = (image[left] + image[right]) / 2;
					if (strcmp(type, "MHC") == 0)
						newImage[blue_pos] += beta * (image[center] - 0.2*(image[left2] + image[right2] + image[left_top] + image[left_bot] + image[right_top] + image[right_bot]) + 0.1*(image[top2] + image[bot2]));
				}
			}
			else if (i % 2 == 1) //on blue pixel
			{
				newImage[blue_pos] = image[center];
				//set green pixel value
				newImage[green_pos] = (image[top] + image[right] + image[left] + image[bot]) / 4;
				if (strcmp(type, "MHC") == 0)
					newImage[green_pos] += alpha * (image[center] - 0.25*(image[left2] + image[right2] + image[top2] + image[bot2]));
				//set red pixel value
				newImage[red_pos] = (image[right_top] + image[left_top] + image[right_bot] + image[left_bot]) / 4;
				if (strcmp(type, "MHC") == 0)
					newImage[red_pos] += gamma * (image[center] - 0.25*(image[left2] + image[right2] + image[top2] + image[bot2]));
			}
			else //on red pixel
			{
				newImage[red_pos] = image[center];
				//set green pixel value
				newImage[green_pos] = (image[bot] + image[left] + image[right] + image[top]) / 4;
				if (strcmp(type, "MHC") == 0)
					newImage[green_pos] += alpha * (image[center] - 0.25*(image[left2] + image[right2] + image[top2] + image[bot2]));
				//set blue pixel value
				newImage[blue_pos] = (image[left_bot] + image[right_bot] + image[left_top] + image[right_top]) / 4;
				if (strcmp(type, "MHC") == 0)
					newImage[blue_pos] += gamma * (image[center] - 0.25*(image[left2] + image[right2] + image[top2] + image[bot2]));
			}

		}
	return newImage;
}

u32* calculate_hist(u8* image, int height, int width)
{
	u32* hist = new u32[256];
	int size = height * width;
	for (int i = 0; i < 256; ++i)
		hist[i] = 0;
	for (int i = 0; i < size; ++i)
		hist[image[i]]++;
	return hist;
}

u8* getTransferMap(u32* hist, int height, int width)
{
	double size = height * width;
	u8* map = new u8[256];
	double p = 0;
	for (int i = 0; i < 256; ++i)
	{
		p += hist[i] / size;
		map[i] = u8(p * 255);
	}
	return map;
}

u8* transferImageByMap(u8* map, u8* image, int height, int width)
{
	u8* newImage = new u8[height*width];
	for (int i = 0; i < height*width; ++i)
		newImage[i] = map[image[i]];
	return newImage;
}

u8* enhanceImageByHist(u8* image, u32* hist, int height, int width)
{
	u8* map = getTransferMap(hist, height, width);
	u8* newImage = transferImageByMap(map, image, height, width);
	delete[] map;
	return newImage;
}

u8* enhanceImageByCumulative(u8* image, u32* hist, int height, int width)
{
	int total = height * width;
	double unit = total / 256.0;
	u32 hist_cu[256] = { 0 };
	int p = 0;
	for (int i = 0; i < 256; ++i)
	{
		hist_cu[i] = p;
		p += hist[i];
	}
	u8* newImage = new u8[total];
	for (int i = 0; i < total; ++i)
	{
		int index = hist_cu[image[i]]++;
		int gray = index / unit;
		newImage[i] = gray;
	}
	return newImage;
}
