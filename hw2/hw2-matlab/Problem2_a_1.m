%copyright: ZhenyeJiang, zhenyeji@usc.edu
clear;
bridge_path="HW2_images/bridge.raw";
bridge_gray=readraw(bridge_path,400,600);
height=400;
width=600;
G=zeros(height,width);
rand('seed',1203);
for i=1:height
    for j=1:width
        t=randint2(1,1,[0,255]);
        if bridge_gray(i,j)>=t
            G(i,j)=255;
        end
    end
end
figure;imshow(bridge_gray);
figure;imshow(G);
            