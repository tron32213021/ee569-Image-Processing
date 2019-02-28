clear;
I=readraw("HW3_Images/deer.raw",691,550);
I=double(I/255);
imshow(I);
G=remove_defect(I,5);
imshow(G);