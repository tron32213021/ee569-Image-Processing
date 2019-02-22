#pragma once
#include "uni.h"

class Img
{
private:
	static int counts;
    int height;
    int width;
    int channel;
    u8* image;
	std::string name;
private:
	u8* readImage(const char* fileName, int size);
	void reflectPos(int& x, int& y);
public:
	Img();
	Img(Img R, Img G, Img B);
    Img(int height,int width,int channel=1,std::string name="Default_");
    Img(u8* image,int height,int width,int channel=1, std::string name = "Default_");
	
	int getHeight();
	int getWidth();
	int getChannel();
	u8* getImage();
	std::string getName();
	void resetName(std::string name);

	u8 get(int x, int y, int z=0);
	void set(u8 value, int x, int y, int z=0);
	void setShape(int height, int width, int channel=1);
	void setShape(Img I);
	void setImage(u8* image);
	void initSpace();
	Img getCh_Image(int channel);

	void loadImage(std::string path);
	void writeImage(std::string basePath);
	~Img();
};