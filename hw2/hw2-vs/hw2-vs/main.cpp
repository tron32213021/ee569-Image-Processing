#include "uni.h"
#include "Img.h"
#include "Img_Tools.h"
#include "opencv_Tools.h"
int main()
{
	std::string cat_file = "cat.raw";
	Img cat = Img(300, 390, 1, "cat");
	cat.loadImage(cat_file);
	showImage(&cat);

	Img cat_demos = Img(300, 390, 3, "cat_demos");
	demosaicing(&cat_demos, &cat, "MHC");
	showImage(&cat_demos);
	return 0;
}