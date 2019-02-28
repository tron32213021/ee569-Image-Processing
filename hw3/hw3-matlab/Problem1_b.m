clear;
I=readraw("HW3_Images/pepper.raw",256,256);
imshow(I);
G=spatial_warp(I,0.25);
imshow(uint8(G));