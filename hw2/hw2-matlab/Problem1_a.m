%copyright: ZhenyeJiang, zhenyeji@usc.edu
clear;
sobel_row=[-1,0,1;-2,0,2;-1,0,1];
sobel_col=[-1,-2,-1;0,0,0;1,2,1];
%%%%%%%%%%%%%%% Tiger %%%%%%%%%%%%%%%%%%%
figure;
tiger_path="HW2_images/Tiger.raw";
tiger_original=readraw(tiger_path,321,481,3);
%imshow(tiger_original);
tiger_gray=rgb2gray(tiger_original);
%imshow(tiger_gray);
tiger_sobel_row=do_filter(tiger_gray,sobel_row,4);
tiger_sobel_row_nor=uint8(Normalize(tiger_sobel_row));
%figure;imshow(tiger_sobel_row_nor); 
tiger_sobel_col=do_filter(tiger_gray,sobel_col,4);
tiger_sobel_col_nor=uint8(Normalize(tiger_sobel_col));
%figure;imshow(tiger_sobel_col_nor); 
tiger_sobel_values=getSobelValue(tiger_sobel_row,tiger_sobel_col);
tiger_sobel_edge=getEdges(tiger_sobel_values,0.2);
%figure;imshow(tiger_sobel_edge);

%%%%%%%%%%%%%% Pig %%%%%%%%%%%%%%%%%%%%%%
figure;
pig_path="HW2_images/Pig.raw";
pig_original=readraw(pig_path,321,481,3);
%imshow(pig_original);
pig_gray=rgb2gray(pig_original);
%imshow(pig_gray);
pig_sobel_row=do_filter(pig_gray,sobel_row,4);
pig_sobel_row_nor=uint8(Normalize(pig_sobel_row));
figure;imshow(pig_sobel_row_nor); 
pig_sobel_col=do_filter(pig_gray,sobel_col,4);
pig_sobel_col_nor=uint8(Normalize(pig_sobel_col));
figure;imshow(pig_sobel_col_nor);
pig_sobel_values=getSobelValue(pig_sobel_row,pig_sobel_col);
%pig_sobel_edge=getEdges(pig_sobel_values,0.27);
figure;imshow(getEdges(pig_sobel_values,0.2));
figure;imshow(getEdges(pig_sobel_values,0.27));
figure;imshow(getEdges(pig_sobel_values,0.3));
figure;imshow(getEdges(pig_sobel_values,0.5));