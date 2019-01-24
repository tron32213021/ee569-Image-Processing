/* 
copyright: Zhenye Jiang
Name:	Zhenye Jiang
USC_ID:	5553039273
Email:	zhenyeji@usc.edu
Submission date: Jan 22 2019
*/
#include "hw1.h"
#include "myLib.h"
#include "showImage.h"
#include <string>
namespace hw1
{
	void q1_a()
	{
		char image_Path[] = "HW1_images/cat.raw";
		int height = 300;
		int width = 390;
		u8* imageRAW = readImage(image_Path, height*width);
		/************** (1) ******************/
		u8* image_fix = demosaicing(imageRAW, height, width);
		//showGrayImage(imageRAW, height, width,"cat.raw");
		showRGBImage(image_fix, height, width,"cat_fix.raw");
		/*************************************/
		delete[] imageRAW;
		delete[] image_fix;

	}
	void q1_b()
	{
		char image_Path[] = "HW1_images/cat.raw";
		int height = 300;
		int width = 390;
		u8* imageRAW = readImage(image_Path, height*width);
		/************** (1) ******************/
		u8* image_fix_MHC = demosaicing(imageRAW, height, width, "MHC");
		showRGBImage(image_fix_MHC, height, width,"cat_fix_MHC.raw");
		/*************************************/

		delete[] imageRAW;
		delete[] image_fix_MHC;
	}

	void q1_c_helper(const char* imagepath, int height, int width,const char* name)
	{
		char t_name[256];
		/****************** image histogram*********************/
		sprintf(t_name, "%s%s", name, " Histogram");
		u8* imageGray = readImage(imagepath, height*width);
		u32* hist = calculate_hist(imageGray, height, width);
		printu32Number(hist, 256);
		u8* histImage = createHistImage(hist, height, width);
		//showGrayImage(imageGray, height, width);
		/***********************************************************/
		/****************** image transfer-function Enhanced histogram*********************/
		sprintf(t_name, "%s%s", name, " transfer-function Enhanced Histogram");
		u8* enhancedImage = enhanceImageByHist(imageGray, hist, height, width);
		u32* hist_enhanced = calculate_hist(enhancedImage, height, width);
		printu32Number(hist_enhanced, 256);
		u8* histImage_enhanced = createHistImage(hist_enhanced, height, width);
		showGrayImage(enhancedImage, height, width,"transfer-function Enhanced Image.raw");
		/**********************************************************************************/
		/****************** image cumulative-based Enhanced histogram*********************/
		sprintf(t_name, "%s%s", name, " cumulative-based Enhanced Histogram");
		u8* enhancedImage_cu = enhanceImageByCumulative(imageGray, hist, height, width);
		u32* hist_enhanced_cu = calculate_hist(enhancedImage_cu, height, width);
		printu32Number(hist_enhanced_cu, 256);
		u8* histImage_enhanced_cu = createHistImage(hist_enhanced_cu, height, width);
		showGrayImage(enhancedImage_cu, height, width,"cumulative-based Enhanced Image.raw");
		/********************************************************************************/

		delete[] imageGray, hist, histImage;
		delete[] enhancedImage, hist_enhanced, histImage_enhanced;
		delete[] enhancedImage_cu, hist_enhanced_cu, histImage_enhanced_cu;
	}
	void q1_c()
	{
		char image_dark_Path[] = "HW1_images/rose_dark.raw";
		char image_bright_Path[] = "HW1_images/rose_bright.raw";
		char image_mix_Path[] = "HW1_images/rose_mix.raw";
		int height = 400;
		int width = 400;
		q1_c_helper(image_dark_Path, height, width, "rose_dark");
		q1_c_helper(image_bright_Path, height, width, "rose_bright");
		q1_c_helper(image_mix_Path, height, width, "rose_mix");
	}

	void q2_a()
	{
		char image_path[] = "HW1_images/pepper_uni.raw";
		char image_free_path[]= "HW1_images/pepper.raw";
		int height = 256;
		int width = 256;
		u8* image = readImage(image_path, height*width);
		u8* image_free = readImage(image_free_path, height*width);
		//showGrayImage(image, height, width,"pepper_free.raw");
		double PSNR[10];
		
		for (int i = 3; i <= 21; i+=2)
		{
			u8* image_filtered = weightedMeanFilter(image, height, width, i);
			PSNR[i/2-1] = calcPSNR(image_filtered, image_free, height, width);
			delete[] image_filtered;
		}
		for (int i = 0; i < 10; ++i)
			printf("%2.3f,", PSNR[i]);
		printf("\n");
		for (int i = 3; i <= 21; i+=2)
		{
			u8* image_filtered_Gaussian = weightedMeanFilter(image, height, width, i, "Gaussian");
			PSNR[i / 2 - 1] = calcPSNR(image_filtered_Gaussian, image_free, height, width);
			delete[] image_filtered_Gaussian;
		}
		for (int i = 0; i < 10; ++i)
			printf("%2.3f,", PSNR[i]);
		printf("\n");
		
		u8* image_filtered_Bilateral = weightedMeanFilter(image, height, width, 7, "bilateral");
		u8* image_filtered_Non_local = weightedMeanFilter(image, height, width, 7, "non-local");
		u8* image_filtered_Gaussian = weightedMeanFilter(image, height, width, 7, "Gaussian");
		//showGrayImage(image_filtered, height, width,"Mean");
		showGrayImage(image_filtered_Gaussian, height, width,"pepper_Gaussian.raw");
		showGrayImage(image_filtered_Bilateral, height, width,"pepper_Bilateral.raw");
		showGrayImage(image_filtered_Non_local, height, width,"pepper_Non_Local.raw");
		delete[] image, image_free, image_filtered_Bilateral, image_filtered_Non_local;
	}
	void q2_b()
	{
		char image_rose_path[] = "HW1_images/rose_color.raw";
		char image_rose_noise_path[] = "HW1_images/rose_color_noise.raw";
		int height = 256;
		int width = 256;
		int channel = 3;
		u8* image_rose = readImage(image_rose_path, height*width*channel);
		u8* image_rose_noise = readImage(image_rose_noise_path, height*width*channel);
		//showRGBImage(image_rose_noise, height, width);
		u8* image_filtered = removeMixNoise(image_rose_noise, height, width, channel);
		showRGBImage(image_filtered, height, width,"Rose_color_filtered.raw");
		delete[] image_rose, image_rose_noise, image_filtered;
	}
	void q2_c()
	{
		char image_pepper_path[] = "HW1_images/pepper_dark.raw";
		char image_pepper_noise_path[] = "HW1_images/pepper_dark_noise.raw";
		int height = 256;
		int width = 256;
		u8* image_pepper = readImage(image_pepper_path, height*width);
		u8* image_pepper_noise = readImage(image_pepper_noise_path, height*width);
		u8* image_filtered = removeShotNoise(image_pepper_noise, height, width);
	
		//showGrayImage(image_pepper, height, width);
		//showGrayImage(image_pepper_noise, height, width);
		showGrayImage(image_filtered,height,width,"pepper_dark filtered.raw");
		delete[] image_pepper, image_pepper_noise, image_filtered;
	}
};