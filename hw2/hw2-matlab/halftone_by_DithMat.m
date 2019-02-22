%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = halftone_by_DithMat(I,TH)
    [height,width]=size(I);
    [N,~]=size(TH);
    G=zeros(height,width);
    for i=1:height
        for j=1:width
            if I(i,j)>=TH(mod(i-1,N)+1,mod(j-1,N)+1)
                G(i,j)=255;
            end
        end
    end
end

