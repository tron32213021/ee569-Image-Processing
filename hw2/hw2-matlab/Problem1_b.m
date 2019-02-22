%copyright: ZhenyeJiang, zhenyeji@usc.edu
clear;
tiger_path="HW2_images/Tiger.raw";
pig_path="HW2_images/Pig.raw";
tiger_original=readraw(tiger_path,321,481,3);
tiger_gray=rgb2gray(tiger_original);
pig_original=readraw(pig_path,321,481,3);
pig_gray=rgb2gray(pig_original);

%tiger_edge=~edge(tiger_gray,'canny',[0.2,0.3]);
%pig_edge=~edge(pig_gray,'canny',[0.2,0.3]);
figure;imshow(~edge(pig_gray,'canny',[0.1,0.5]));
figure;imshow(~edge(pig_gray,'canny',[0.1,0.3]));
figure;imshow(~edge(pig_gray,'canny',[0.2,0.5]));
figure;imshow(~edge(pig_gray,'canny',[0.2,0.3]));
%figure;imshow(pig_edge);
