#include "hw1.h"
#include "myLib.h"
#include "showImage.h"
namespace hw1
{
	void q1_a()
	{
		char image_Path[] = "HW1_images/cat.raw";
		int height = 300;
		int width = 390;
		u8* imageRAW = readImage(image_Path, height*width);
		u8* image_fix = demosaicing(imageRAW, height, width);
		showRGBImage(image_fix, height, width);

		delete[] imageRAW;
		delete[] image_fix;

	}
	void q1_b()
	{
		char image_Path[] = "HW1_images/cat.raw";
		int height = 300;
		int width = 390;
		u8* imageRAW = readImage(image_Path, height*width);
		u8* image_fix_MHC = demosaicing(imageRAW, height, width, "MHC");
		showGrayImage(imageRAW, height, width);
		showRGBImage(image_fix_MHC, height, width);

		delete[] imageRAW;
		delete[] image_fix_MHC;
	}
	void q1_c()
	{
		char image_Path[] = "HW1_images/rose_mix.raw";
		int height = 400;
		int width = 400;
		u8* imageGray = readImage(image_Path, height*width);
		u32* hist = calculate_hist(imageGray, height, width);
		u8* histImage = createHistImage(hist, height, width);

		u8* enhancedImage = enhanceImageByHist(imageGray, hist, height, width);
		u32* hist_enhanced = calculate_hist(enhancedImage, height, width);
		u8* histImage_enhanced = createHistImage(hist_enhanced, height, width);

		u8* enhancedImage_cu = enhanceImageByCumulative(imageGray, hist, height, width);
		u32* hist_enhanced_cu = calculate_hist(enhancedImage_cu, height, width);
		u8* histImage_enhanced_cu = createHistImage(hist_enhanced_cu, height, width);

		showGrayImage(histImage, height, width);

		showGrayImage(histImage_enhanced, height, width);
		showGrayImage(enhancedImage, height, width);

		showGrayImage(histImage_enhanced_cu, height, width);
		showGrayImage(enhancedImage_cu, height, width);
		delete[] imageGray, hist, histImage;
		delete[] enhancedImage, hist_enhanced, histImage_enhanced;
		delete[] enhancedImage_cu, hist_enhanced_cu, histImage_enhanced_cu;
	}

	void q2_a()
	{

	}
	void q2_b()
	{

	}
	void q2_c()
	{

	}
};