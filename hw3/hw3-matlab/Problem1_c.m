clear;
I=readraw("HW3_Images/classroom.raw",712,1072);
imshow(I);
G=uint8(lens_distortion_correction(I));
figure;imshow(G);