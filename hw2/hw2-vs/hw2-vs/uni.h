/*
copyright: Zhenye Jiang
Name:	Zhenye Jiang
USC_ID:	5553039273
Email:	zhenyeji@usc.edu
Submission date: Jan 22 2019
*/
#pragma once
#define u8 unsigned char
#define u32 unsigned int
#include <string>
#include "Img_Tools.h"

using namespace std;
class Shape
{
public:
	int n_row;
	int n_col;
	int n_cha;
	Shape(int n_row, int n_col, int n_cha);
	int getSize();
};
template <class T> 
class PixelGetter
{
public:
	Shape s;
	T* p;
public:
	PixelGetter(T* p, Shape s);
	T get(int x, int y,int z=1);
};
void loadImage(u8* output, std::string path,Shape s);
void writeImage(u8* input,Shape s,string name);


