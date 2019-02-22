#include "uni.h"
template<class T>
inline PixelGetter<T>::PixelGetter(T * p, Shape s)
{
	this->p = p;
	this->s = s;
}
void reflectPos(int & x, int & y,Shape s)
{
	if (x < 0)
		x = -x;
	if (x >= s.n_row)
		x = 2 * s.n_row - x - 1;
	if (y < 0)
		y = -y;
	if (y >= s.n_col)
		y = 2 * s.n_col - y - 1;
}
template<class T>
inline T PixelGetter<T>::get(int x, int y,int z)
{
	while (x < 0 || x >= height || y < 0 || y >= width)
		reflectPos(x, y, s);

	return p[(x*width + y)*channel + z];
}

void loadImage(u8* output, std::string path,Shape s)
{
	const char* fileName = path.c_str();
	FILE* file;
	int size = s.n_row*s.n_col*s.n_cha;
	u8* image = new u8[size];
	if (!(file = fopen(fileName, "rb")))
	{
		printf("Cannot open file: %s\n", fileName);
		exit(1);
	}
	fread(image, sizeof(u8), size, file);
	fclose(file);
	memcpy(output, image, size);
	delete[] image;
}

void writeImage(u8* input, Shape s,string name)
{
	const char* fileName = (name + std::string(".raw")).c_str();
	FILE* file;
	if (!(file = fopen(fileName, "wb")))
	{
		printf("Cannot open file: %s\n", fileName);
		exit(1);
	}
	fwrite(input, sizeof(u8), s.n_cha*s.n_col*s.n_row, file);
	fclose(file);
}

Shape::Shape(int n_row, int n_col, int n_cha)
{
	this->n_cha = n_cha;
	this->n_col = n_col;
	this->n_row = n_row;
}

int Shape::getSize()
{
	return n_cha*n_col*n_row;
}
