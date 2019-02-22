%copyright: ZhenyeJiang, zhenyeji@usc.edu
clear;
house=imread('HW2_images/House.png');
pig=imread('HW2_images/Pig.jpg');
tiger=imread('HW2_images/Tiger.jpg');
image=pig;
p=0.2;

edge=SE_edge_dectector(image);
cd ..;
[height,width]=size(edge);
G=ones(height,width)*255;
for i=1:height
    for j=1:width
        if edge(i,j)>=p
            G(i,j)=0;
        end
    end
end
imshow(G);
figure;imshow(1-edge);
