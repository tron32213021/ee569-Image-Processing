#include "Img_Tools.h"
////////////////////////////////////////////////////////
u8 fix(int value)
{
	return fmin(fmax(value, 0), 255);
}
/////////////////////////////////////////////////////////
void demosaicing(Img* newImage, Img* image, std::string type)
{
	newImage->initSpace();
	double alpha = 1.0 / 2, beta = 5.0 / 8, gamma = 3.0 / 4;
	int height = image->getHeight();
	int width = image->getWidth();
	int r = 0;
	int g = 1;
	int b = 2;
	u8 center, left, right, top, bot, left_top, left_bot, right_top, right_bot, top2, bot2, left2, right2;
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			center = image->get(i, j);
			left = image->get(i, j - 1);
			right = image->get(i, j + 1);
			top = image->get(i - 1, j);
			bot = image->get(i + 1, j);
			left2 = image->get(i, j - 2);
			right2 = image->get(i, j + 2);
			top2 = image->get(i - 2, j);
			bot2 = image->get(i + 2, j);
			left_top = image->get(i - 1, j - 1);
			left_bot = image->get(i + 1, j - 1);
			right_top = image->get(i - 1, j + 1);
			right_bot = image->get(i + 1, j + 1);
			///////////////////////////////////////
			u8 value;
			if (i % 2 == j % 2) //on green pixel
			{

				//set green pixel value
				newImage->set(center, i, j, g);

				if (i % 2 == 0)
				{
					//set red pixel value
					newImage->set((right + left) / 2, i, j, r);
					if (type.compare("MHC") == 0)
					{
						value = fix((int)newImage->get(i, j, r) + beta * (center
							- 0.2*(left2 + right2 + left_top + left_bot + right_top + right_bot)
							+ 0.1*(top2 + bot2)));
						newImage->set(value, i, j, r);

					}
					//set blue pixel value
					newImage->set((bot + top) / 2, i, j, b);
					if (type.compare("MHC") == 0)
					{
						value = fix((int)newImage->get(i, j, b) + beta * (center
							- 0.2*(top2 + bot2 + left_top + left_bot + right_top + right_bot)
							+ 0.1*(left2 + right2)));
						newImage->set(value, i, j, b);
					}
				}
				else
				{
					//set red pixel value
					newImage->set((top + bot) / 2, i, j, r);
					if (type.compare("MHC") == 0)
					{
						value= fix((int)newImage->get(i,j,r) + beta * (center
							- 0.2*(top2 + bot2 + left_top + left_bot + right_top + right_bot)
							+ 0.1*(left2 + right2)));
						newImage->set(value, i, j, r);
					}
					//set blue pixel value
					newImage->set((left + right) / 2, i, j, b);
					if (type.compare("MHC") == 0)
					{
						value= fix((int)newImage->get(i,j,b) + beta * (center
							- 0.2*(left2 + right2 + left_top + left_bot + right_top + right_bot)
							+ 0.1*(top2 + bot2)));
						newImage->set(value, i, j, b);
					}
				}
			}
			else if (i % 2 == 1) //on blue pixel
			{
				newImage->set(center, i, j, b);
				//set green pixel value
				newImage->set((top + right + left + bot) / 4, i, j, g);
				if (type.compare("MHC") == 0)
				{
					value= fix((int)newImage->get(i,j,g) + alpha * (center - 0.25*(left2 + right2 + top2 + bot2)));
					newImage->set(value, i, j, g);
				}
				//set red pixel value
				newImage->set((right_top + left_top + right_bot + left_bot) / 4, i, j, r);
				if (type.compare("MHC") == 0)
				{
					value= fix((int)newImage->get(i,j,r) + gamma * (center - 0.25*(left2 + right2 + top2 + bot2)));
					newImage->set(value, i, j, r);
				}
			}
			else //on red pixel
			{
				newImage->set(center, i, j, r);
				//set green pixel value
				newImage->set((bot + left + right + top) / 4, i, j, g);
				if (type.compare("MHC") == 0)
				{
					value= fix((int)newImage->get(i,j,g) + alpha * (center - 0.25*(left2 + right2 + top2 + bot2)));
					newImage->set(value, i, j, g);
				}
				//set blue pixel value
				newImage->set((left_bot + right_bot + left_top + right_top) / 4, i, j, b);
				if (type.compare("MHC") == 0)
				{
					value= fix((int)newImage->get(i,j,b)+ gamma * (center - 0.25*(left2 + right2 + top2 + bot2)));
					newImage->set(value, i, j, b);
				}
			}

		}
}
