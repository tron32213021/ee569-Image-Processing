%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = Normalize( I )
    min=0;
    max=255;
    min_t=99999;
    max_t=-99999;
    [height,width]=size(I);
    G=zeros(height,width);
    for i=1:height
        for j=1:width
            if I(i,j)<min_t
                min_t=I(i,j);
            end
            if I(i,j)>max_t
                max_t=I(i,j);
            end
        end
    end
    for i=1:height
        for j=1:width
            G(i,j)=(I(i,j)-min_t)/(max_t-min_t)*(max-min)+min;
            %G(i,j)=uint8(G(i,j));
        end
    end
end

