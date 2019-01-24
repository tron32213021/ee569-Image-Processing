#include "opencv_Tools.h"
#include <opencv2/opencv.hpp>
void showImage(Img* image)
{
	if (image->getChannel() == 1)
	{
		cv::Mat myMat(image->getHeight(), image->getWidth(), CV_8UC1, (void *)image->getImage());
		cv::imshow(image->getName(), myMat);
		cv::waitKey(0);
	}
	else
	{
		cv::Mat myMat(image->getHeight(), image->getWidth(), CV_8UC3, (void *)image->getImage());
		cv::Mat dst;
		cv::cvtColor(myMat, dst, cv::COLOR_RGB2BGR);
		cv::imshow(image->getName(), dst);
		cv::waitKey(0);
	}
}
