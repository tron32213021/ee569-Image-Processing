#include "uni.h"
#include "opencv_Tools.h"

using namespace std;
void p1_a_main()
{
	int sobel_row_u8[] = { -1,0,1,-2,0,2,-1,0,1 };
	int sobel_col_u8[] = { -1,-2,-1,0,0,0,1,2,1 };
	Shape s_mask(3, 3, 1);
	Shape s_rgb(321, 481, 3);
	Shape s_gray(321, 481,1);

	string imageTiger_path = "HW2_images_new/HW2_images/Tiger.raw";
	u8 tiger_ori[321][481][3];
	loadImage((u8*)tiger_ori, imageTiger_path, s_rgb);
	showImage((u8*)tiger_ori,s_rgb,"Tiger original");
	
	u8 tiger_gray[321][481];
	RGB2Gray((u8*)tiger_gray, (u8*)tiger_ori,s_gray);
	showImage((u8*)tiger_gray,s_gray,"Tiger Gray");

	double tiger_sobel_row[321][481];
	double tiger_sobel_col[321][481];

	do_filter((double*)tiger_sobel_row, (u8*)tiger_gray, sobel_row_u8, 4, s_gray, s_mask);
	do_filter((double*)tiger_sobel_col, (u8*)tiger_gray, sobel_col_u8, 4, s_gray, s_mask);
	showImage((u8*)tiger_sobel_row, s_gray, "Tiger Gray");


	
}