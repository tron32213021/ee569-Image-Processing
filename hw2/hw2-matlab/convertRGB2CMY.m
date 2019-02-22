%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = convertRGB2CMY(I)
    [height,width,channel]=size(I);
    G=zeros(height,width);
    for i=1:height
        for j=1:width
            for z=1:channel
                G(i,j,z)=255-I(i,j,z);
            end
        end
    end
end

