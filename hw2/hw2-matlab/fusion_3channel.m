%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = fusion_3channel(c1,c2,c3)
    [height,width]=size(c1);
    G=zeros(height,width,3);
    for i=1:height
        for j=1:width
            G(i,j,1)=c1(i,j);
            G(i,j,2)=c2(i,j);
            G(i,j,3)=c3(i,j);
        end
    end
end

