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
		showRGBImage(image_fix, height, width);
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
		showRGBImage(image_fix_MHC, height, width);
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
		u8* histImage = createHistImage(hist, height, width);
		showGrayImage(histImage, height, width, t_name);
		/***********************************************************/
		/****************** image transfer-function Enhanced histogram*********************/
		sprintf(t_name, "%s%s", name, " transfer-function Enhanced Histogram");
		u8* enhancedImage = enhanceImageByHist(imageGray, hist, height, width);
		u32* hist_enhanced = calculate_hist(enhancedImage, height, width);
		u8* histImage_enhanced = createHistImage(hist_enhanced, height, width);
		showGrayImage(histImage_enhanced, height, width, t_name);
		/**********************************************************************************/
		/****************** image cumulative-based Enhanced histogram*********************/
		sprintf(t_name, "%s%s", name, " cumulative-based Enhanced Histogram");
		u8* enhancedImage_cu = enhanceImageByCumulative(imageGray, hist, height, width);
		u32* hist_enhanced_cu = calculate_hist(enhancedImage_cu, height, width);
		u8* histImage_enhanced_cu = createHistImage(hist_enhanced_cu, height, width);
		showGrayImage(histImage_enhanced_cu, height, width, t_name);
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
		int height = 256;
		int width = 256;
		u8* image = readImage(image_path, height*width);
		showGrayImage(image, height, width);
		u8* image_filtered = weightedMeanFilter(image, height, width, 7);
		u8* image_filtered_Gaussian = weightedMeanFilter(image, height, width, 7,"Gaussian");
		u8* image_filtered_Bilateral = weightedMeanFilter(image, height, width, 7, "bilateral");
		u8* image_filtered_Non_local = weightedMeanFilter(image, height, width, 20, "non-local");
		//showGrayImage(image_filtered, height, width,"Mean");
		//showGrayImage(image_filtered_Gaussian, height, width,"Gaussian");
		showGrayImage(image_filtered_Bilateral, height, width,"Bilateral");
		showGrayImage(image_filtered_Non_local, height, width,"Non_Local");
		delete[] image, image_filtered, image_filtered_Gaussian,image_filtered_Bilateral, image_filtered_Non_local;
	}
	void q2_b()
	{

	}
	void q2_c()
	{

	}
};