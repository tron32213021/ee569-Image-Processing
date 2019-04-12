%0. generate 25 laws filters and read images
Laws_Filters;
texture=zeros(12,128,128);
for i=1:12
    texture(i,:,:)=readraw("./HW4_Images/texture"+i+".raw",128,128);
    image=reshape(texture(i,:,:),[128,128]);
    subplot(4,3,i);imshow(image/255);
end

%1-2.generate 25-D feature vector
Energy=zeros(25,12);
for i=1:12
    Energy(:,i)=getSampleEnergy(texture(i,:,:)/255,filters);
end
Energy=Energy';
Energy=(Energy-mean(Energy))./sqrt(var(Energy));
%Energy=Energy(:,2:25);
%3. use PCA to reduce dimension
C=cov(Energy);
[V,D]=eig(C);
coff=Energy*V(:,23:25);

figure;plot3(coff(:,1),coff(:,2),coff(:,3),'.');
%4. kmeans
idx_25D=kmeans(Energy,4);
idx_3D=kmeans(coff,4);
