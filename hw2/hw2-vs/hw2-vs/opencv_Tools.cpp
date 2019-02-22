#include "opencv_Tools.h"
#include <opencv2/opencv.hpp>
void showImage(u8* image,Shape s,string name)
{
	if (s.n_cha == 1)
	{
		cv::Mat myMat(s.n_row, s.n_col, CV_8UC1, (void *)image);
		cv::imshow(name, myMat);
		cv::waitKey(0);
	}
	else
	{
		cv::Mat myMat(s.n_row, s.n_col, CV_8UC3, (void *)image);
		cv::Mat dst;
		cv::cvtColor(myMat, dst, cv::COLOR_RGB2BGR);
		cv::imshow(name, dst);
		cv::waitKey(0);
	}
}

void RGB2Gray(u8* output, u8* input, Shape s)
{
	cv::Mat myMat(s.n_row, s.n_col, CV_8UC3, (void *)input);
	cv::Mat dst;
	cv::cvtColor(myMat, dst, cv::COLOR_RGB2GRAY);
	u8* image = new u8[s.n_row*s.n_col];
	memcpy((void*)output, (void*)dst.data, s.n_row*s.n_col);

}