clear;
pattern1=readraw("HW3_Images/pattern1.raw",375,375);
pattern2=readraw("HW3_Images/pattern2.raw",375,375);
pattern3=readraw("HW3_Images/pattern3.raw",375,375);
pattern4=readraw("HW3_Images/pattern4.raw",375,375);
pattern1=double(pattern1/255);
pattern2=double(pattern2/255);
pattern3=double(pattern3/255);
pattern4=double(pattern4/255);

G=skeletenize(pattern2);
imshow(G);