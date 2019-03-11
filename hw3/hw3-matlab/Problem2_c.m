clear;
I=readraw("HW3_Images/rice.raw",500,690,3);
gray=rgb2gray(I);
edges=edge(gray,'canny',[0,0.1]);
a=imdilate(edges,ones(5,5));
img=imfill(a,'hole');
b=imerode(img,ones(11,11));
imshow(b);
G=thin(b);
G=imdilate(G,ones(3,3));
G=shrink(G);
imshow(G);
points=find_lonely_dots(G);
[N,C]=myClasses(points,size(G));
hold on; plot(C(:,2),C(:,1),'*');
sum(N)



red=[];
blue=[];
green=[];
yellow=[];
pink=[];
classes_size=zeros(1,11);
for i=1:11
    [ppp,s]=getGrainFromBig2Small(b,points,C,i);
    red=[red;ppp(1,:)];
    blue=[blue;ppp(2,:)];
    green=[green;ppp(3,:)];
    yellow=[yellow;ppp(4,:)];
    pink=[pink;ppp(5,:)];
    classes_size(i)=sum(s)/5;
end

figure;imshow(G);
hold on;
plot(red(:,2),red(:,1),'r.');
plot(blue(:,2),blue(:,1),'b.');
plot(green(:,2),green(:,1),'g.');
plot(yellow(:,2),yellow(:,1),'y.');
plot(pink(:,2),pink(:,1),'m.');

figure;imshow(gray);
hold on;
plot(red(:,2),red(:,1),'r*');
plot(blue(:,2),blue(:,1),'b*');
plot(green(:,2),green(:,1),'g*');
plot(yellow(:,2),yellow(:,1),'y*');
plot(pink(:,2),pink(:,1),'m*');

[~,ind]=sort(classes_size);
ind