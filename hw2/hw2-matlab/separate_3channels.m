%copyright: ZhenyeJiang, zhenyeji@usc.edu
function [c1,c2,c3] = separate_3channels(I)
    [height,width,channel]=size(I);
    c1=zeros(height,width);
    c2=zeros(height,width);
    c3=zeros(height,width);
    for i=1:height
        for j=1:width
            c1(i,j)=I(i,j,1);
            c2(i,j)=I(i,j,2);
            c3(i,j)=I(i,j,3);
        end
    end
end

