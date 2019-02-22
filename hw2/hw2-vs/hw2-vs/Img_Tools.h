#pragma once
#include "uni.h"

void do_filter(double* output, u8* input, int* filter_mask, double w, Shape s_i, Shape s_m);
