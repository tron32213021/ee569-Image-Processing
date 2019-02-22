%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = getEdges( I,percentage )
    min_t=min(I);
    max_t=max(I);
    th=percentage*(max_t-min_t)+min_t;
    [X,Y]=size(I);
    G=ones(X,Y)*255;
    for i=1:X
        for j=1:Y
            if I(i,j)>=th
                G(i,j)=0;
            end
        end
    end
    G=uint8(G);
end

