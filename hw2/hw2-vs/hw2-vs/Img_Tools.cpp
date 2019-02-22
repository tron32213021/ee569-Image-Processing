#include "uni.h"

////////////////////////////////////////////////////////
void do_filter(double* output, u8* input, int* filter_mask, double w, Shape s_i, Shape s_m)
{
	PixelGetter<u8> i_getter(input, s_i);
	PixelGetter<int> m_getter(filter_mask, s_m);
	int shift_x = s_m.n_row / 2;
	int shift_y = s_m.n_col / 2;
	for(int i=0;i<s_i.n_row;++i)
		for (int j = 0; j < s_i.n_col; ++j)
		{
			double t = 0;
			for (int x = 0; x < s_m.n_row; ++x)
				for (int y = 0; y < s_m.n_col; ++y)
					t += i_getter.get(i - shift_x + x, j - shift_y + y) * m_getter.get(x,y);
			t /= w;
			output[i*s_i.n_col + j] = t;
		}

}