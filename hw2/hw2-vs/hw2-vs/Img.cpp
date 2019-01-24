#include "Img.h"
int Img::counts = 0;
u8 * Img::readImage(const char* fileName, int size)
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

void Img::writeImage(std::string basePath)
{
	const char* fileName = (basePath + this->name + std::string(".raw")).c_str();
	FILE* file;
	if (!(file = fopen(fileName, "wb")))
	{
		printf("Cannot open file: %s\n", fileName);
		exit(1);
	}
	fwrite(image, sizeof(u8),height*width*channel, file);
	fclose(file);
}

void Img::reflectPos(int & x, int & y)
{
	if (x < 0)
		x = -x;
	if (x >= height)
		x = 2 * height - x - 1;
	if (y < 0)
		y = -y;
	if (y >= width)
		y = 2 * width - y - 1;
}

Img::Img()
{
	height = 0;
	width = 0;
	channel = 0;
	image = 0;
	name = "Default_" + std::to_string(counts++);
}

Img::Img(Img R, Img G, Img B)
{
	if (R.getHeight() != G.getHeight() || G.getHeight() != B.getHeight() || B.getHeight() != R.getHeight()
		|| R.getWidth() != G.getWidth() || G.getWidth() != B.getWidth() || B.getWidth() != R.getWidth()
		|| R.getChannel()*G.getChannel()*B.getChannel() != 1)
	{
		printf("ERROR: Three channels have different dimension!\n");
		exit(1);
	}
	this->height = R.getHeight();
	this->width = R.getWidth();
	this->channel = 3;
	this->image = new u8[height*width*channel];
	for(int i=0;i<height;++i)
		for (int j = 0; j < width; ++j)
		{
			this->set(R.get(i, j), i, j, 0);
			this->set(G.get(i, j), i, j, 1);
			this->set(B.get(i, j), i, j, 2);
		}
}

Img::Img(int height, int width, int channel, std::string name)
{
	this->height = height;
	this->width = width;
	this->channel = channel;
	if (name.compare("Default_") == 0)
		this->name = "Default_" + std::to_string(counts++);
	else
		this->name = name;
	this->image = 0;
}

Img::Img(u8 * image, int height, int width, int channel, std::string name)
{
	this->height = height;
	this->width = width;
	this->channel = channel;
	if (name.compare("Default_") == 0)
		this->name = name + std::to_string(counts++);
	else
		this->name = name;
	this->image = image;
}

int Img::getHeight()
{
	return height;
}

int Img::getWidth()
{
	return width;
}

int Img::getChannel()
{
	return channel;
}

u8 * Img::getImage()
{
	return image;
}

std::string Img::getName()
{
	return this->name;
}

void Img::loadImage(std::string path)
{
	const char* fileName = path.c_str();
	if (image)
		delete[] image;
	this->image = readImage(fileName, height*width*channel);
}

u8 Img::get(int x, int y, int z)
{
	while (x < 0 || x >= height || y < 0 || y >= width)
		reflectPos(x, y);
	
	return image[(x*width + y)*channel + z];
}

void Img::set(u8 value, int x, int y, int z)
{
	while (x < 0 || x >= height || y < 0 || y >= width)
		reflectPos(x, y);
	image[(x*width + y)*channel + z] = value;
}



void Img::setShape(int height, int width, int channel)
{	
	
	this->height = height;
	this->width = width;
	this->channel = channel;
	if (image)
		delete[] image;
	image = NULL;
}

void Img::setShape(Img I)
{
	this->height = I.getHeight();
	this->width = I.getWidth();
	this->channel = I.getChannel();
	if (image)
		delete[] image;
	image = NULL;
}

void Img::initSpace()
{
	if (image)
		delete[] image;
	image = new u8[height*width*channel];
}

Img Img::getCh_Image(int channel)
{
	u8* newImage = new u8[height*width];
	int imageSize = width * height;
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			newImage[i*width + j] = image[(i*width + j) * 3 + channel];
	return Img(newImage,height,width,1,name+"channel"+std::to_string(channel));
}

void Img::resetName(std::string name)
{
	this->name = name;
}

Img::~Img()
{
	if (image)
		delete[] image;
}
