/*
copyright: Zhenye Jiang
Name:	Zhenye Jiang
USC_ID:	5553039273
Email:	zhenyeji@usc.edu
Submission date: Jan 22 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include <string.h>
#include <math.h>
ImagePixelGetter::ImagePixelGetter(u8* image, int height, int width,int channel)
{
	this->image = image;
	this->height = height;
	this->width = width;
	this->channel = channel;
}
u8 ImagePixelGetter::get(int x, int y,int z)
{
	if (x < 0)
		x = -x;
	if (x >= height)
		x = 2 * height - x - 1;
	if (y < 0)
		y = -y;
	if (y >= width)
		y = 2 * width - y - 1;
	return image[(x*width + y)*this->channel + z];
}
void printu32Number(u32* hist, int n)
{
	for (int i = 0; i < n-1; ++i)
		printf("%d,", hist[i]);
	printf("%d\n",hist[n-1]);

}
void printu8Number(u8* map, int n)
{
	for (int i = 0; i < n - 1; ++i)
		printf("%d,", map[i]);
	printf("%d\n", map[n - 1]);

}
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

void writeImage(const char* fileName, const u8* image,int size)
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
u8 fix(int value)
{
	return fmin(fmax(value, 0), 255);
}

u8* demosaicing(u8* image, int height, int width, const char* type)
{

	u8* newImage = new u8[height*width * 3];
	double alpha = 1.0 / 2, beta = 5.0 / 8, gamma = 3.0 / 4;
	int imageSize = height * width;
	int r = 0;
	int g = 1;
	int b = 2;
	u8 center, left, right, top, bot, left_top, left_bot, right_top, right_bot, top2, bot2, left2, right2;
	ImagePixelGetter getter(image, height, width);
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			center = getter.get(i, j);
			left = getter.get(i, j - 1);
			right = getter.get(i, j + 1);
			top = getter.get(i - 1, j);
			bot = getter.get(i + 1, j);
			left2 = getter.get(i, j - 2);
			right2 = getter.get(i, j + 2);
			top2 = getter.get(i - 2, j);
			bot2 = getter.get(i + 2, j);
			left_top = getter.get(i-1, j-1);
			left_bot = getter.get(i+1, j-1);
			right_top = getter.get(i-1, j+1);
			right_bot = getter.get(i+1, j+1);
			///////////////////////////////////////
			int red_pos = (i*width+j) * 3 + r;
			int green_pos = (i*width + j) * 3 + g;
			int blue_pos = (i*width + j) * 3 + b;
			if (i % 2 == j % 2) //on green pixel
			{

				//set green pixel value
				newImage[green_pos] = center;

				if (i % 2 == 0)
				{
					//set red pixel value
					newImage[red_pos] = (right + left) / 2;
					if (strcmp(type, "MHC") == 0)
					{
						newImage[red_pos] = fix((int)newImage[red_pos]+beta * (center
							- 0.2*(left2 + right2 + left_top + left_bot + right_top + right_bot)
							+ 0.1*(top2 + bot2)));
						
					}
					//set blue pixel value
					newImage[blue_pos] = (bot + top) / 2;
					if (strcmp(type, "MHC") == 0)
					{
						newImage[blue_pos] = fix((int)newImage[blue_pos]+beta * (center
							- 0.2*(top2 + bot2 + left_top + left_bot + right_top + right_bot)
							+ 0.1*(left2 + right2)));
					}
				}
				else
				{
					//set red pixel value
					newImage[red_pos] = (top + bot) / 2;
					if (strcmp(type, "MHC") == 0)
					{
						newImage[red_pos] = fix((int)newImage[red_pos]+beta * (center
							- 0.2*(top2 + bot2 + left_top + left_bot + right_top + right_bot)
							+ 0.1*(left2 + right2)));
					}
					//set blue pixel value
					newImage[blue_pos] = (left + right) / 2;
					if (strcmp(type, "MHC") == 0)
					{
						newImage[blue_pos] = fix((int)newImage[blue_pos]+beta * (center
							- 0.2*(left2 + right2 + left_top + left_bot + right_top + right_bot)
							+ 0.1*(top2 + bot2)));
					}
				}
			}
			else if (i % 2 == 1) //on blue pixel
			{
				newImage[blue_pos] = center;
				//set green pixel value
				newImage[green_pos] = (top + right + left + bot) / 4;
				if (strcmp(type, "MHC") == 0)
				{
					newImage[green_pos] = fix((int)newImage[green_pos]+alpha * (center - 0.25*(left2 + right2 + top2 + bot2)));
				}
				//set red pixel value
				newImage[red_pos] = (right_top + left_top + right_bot + left_bot) / 4;
				if (strcmp(type, "MHC") == 0)
				{
					newImage[red_pos] = fix((int)newImage[red_pos]+gamma * (center - 0.25*(left2 + right2 + top2 + bot2)));
				}
			}
			else //on red pixel
			{
				newImage[red_pos] = center;
				//set green pixel value
				newImage[green_pos] = (bot + left + right + top) / 4;
				if (strcmp(type, "MHC") == 0)
				{
					newImage[green_pos] = fix((int)newImage[green_pos]+alpha * (center - 0.25*(left2 + right2 + top2 + bot2)));
				}
				//set blue pixel value
				newImage[blue_pos] = (left_bot + right_bot + left_top + right_top) / 4;
				if (strcmp(type, "MHC") == 0)
				{
					newImage[blue_pos] = fix((int)newImage[blue_pos] +gamma * (center - 0.25*(left2 + right2 + top2 + bot2)));
				}
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
	printu8Number(map, 256);
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

double getWeight(u8* image, int height, int width, int i, int j, int k, int l, const char* method)
{
	ImagePixelGetter getter(image, height, width);
	if (strcmp(method, "uniform")==0)
		return 1.0;
	else if (strcmp(method, "Gaussian")==0)
		return exp(-((i - k)*(i - k) + (j - l) * (j - l)) / 2);
	else if (strcmp(method, "bilateral") == 0)
	{
		double sigma_c = 1, sigma_s = 10000;
		return exp(-((i - k)*(i - k) + (j - l) * (j - l)) / (2 * sigma_c) - pow(getter.get(i, j) - getter.get(k, l), 2) / (2 * sigma_s));
	}
	else if (strcmp(method, "non-local") == 0)
	{
		int N = 5;
		int a = 10;
		double h = 5;

		double t = 0;
		for(int t_i=-N/2;t_i<=N/2;++t_i)
			for (int t_j = -N / 2; t_j <= N / 2; ++t_j)
				t += 1 / (sqrt(2 * 3.1415926)*a)*exp(-(t_i*t_i + t_j * t_j) / (2 * a*a))*pow(getter.get(i + t_i, j + t_j) - getter.get(k + t_i, l + t_j), 2);
		return exp(-t / (h*h));
	}
	else
		return 0;
}

u8* weightedMeanFilter(u8* image, int height, int width, int N, const char* method)
{
	u8* newImage = new u8[height*width];
	ImagePixelGetter getter(image, height, width);
	for(int i=0;i<height;++i)
		for (int j = 0; j < width; ++j)
		{
			double s = 0;
			double w = 0;
			double weight;
			for (int x = -N / 2; x <= N / 2; ++x)
				for (int y = -N / 2; y <= N / 2; ++y)
				{
					weight = getWeight(image,height,width,i,j,i+x,j+y,method);
					w += weight;
					s += weight * getter.get(i + x, j + y);
				}
			newImage[i*width + j] = (u8)(s / w);
		}
	return newImage;
}

double calcPSNR(u8* Y, u8* I, int height, int width)
{
	int s = 0;
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			s += (Y[i*width + j] - I[i*width + j])*(Y[i*width + j] - I[i*width + j]);
	double MSE = 1.0*s / (height*width);

	return 10*log10(255*255/MSE);
}

void sort(u8* a, int len)
{
	for(int i=0;i<len-1;++i)
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				u8 t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
}
u8* removeMixNoise(u8* image, int height, int width, int channel)
{
	int N = 5;
	u8* newImage = new u8[height*width*channel];
	ImagePixelGetter getter(image, height, width, channel);
	for (int ch = 0; ch < channel; ++ch)
	{
		for(int i=0;i<height;++i)
			for (int j = 0; j < width; ++j)
			{
				u8* pixels = new u8[N*N];
				int n = 0;
				for(int wx=-N/2;wx<=N/2;++wx)
					for (int wy = -N / 2; wy <= N / 2; ++wy)
					{
						pixels[n++] = getter.get(i + wx, j + wy, ch);
					}
				sort(pixels, N*N);
				newImage[channel*(i*width + j) + ch] = pixels[N*N/2];
			}
	}
	
	u8* res = new u8[height*width*channel];
	ImagePixelGetter newGetter(newImage, height, width, channel);
	for (int ch = 0; ch < channel; ++ch)
	{
		for (int i = 0; i < height; ++i)
			for (int j = 0; j < width; ++j)
			{
				double s = 0;
				double w=0, weight;
				for (int wx = -N / 2; wx <= N / 2; ++wx)
					for (int wy = -N / 2; wy <= N / 2; ++wy)
					{
						weight = exp(-(wx*wx + wy * wy));
						w += weight;
						s += newGetter.get(i + wx, j + wy, ch)*weight;
					}
				
				res[channel*(i*width + j) + ch] = u8(s/w);
			}
	}
	return res;


}

u8* removeShotNoise(u8* image, int height, int width)
{
	int N = 5;
	u8* image_Gaussian = new u8[height*width];
	u8* res= new u8[height*width];
	ImagePixelGetter getter(image_Gaussian, height, width);
	for(int i=0;i<height;++i)
		for (int j = 0; j < width; ++j)
			image_Gaussian[i*width + j] = u8(2 * sqrt(image[i*width + j] + 3.0 / 8));

	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			double s = 0;
			double w = 0, weight;
			for (int wx = -N / 2; wx <= N / 2; ++wx)
				for (int wy = -N / 2; wy <= N / 2; ++wy)
				{
					weight = exp(-(wx*wx + wy * wy));
					w += weight;
					s += getter.get(i + wx, j + wy)*weight;
				}

			res[i*width + j] = u8(s / w);
		}
	delete[] image_Gaussian;
	return res;
}