function [edges,corners] = find_corners_square(I)
    
    I(I<255)=0;
    filter=ones(5,5)*-1;
    filter(3,3)=24;
    edges=edge(I,'canny',[0.2,0.8]);
    
    [height,width]=size(edges);
    min_i=height;min_j=width;max_i=0;max_j=0;
    for i=1:height
        for j=1:width
            if (edges(i,j))
                if i<min_i
                    min_i=i;
                end
                if i>max_i
                    max_i=i;
                end
                if j<min_j
                    min_j=j;
                end
                if j>max_j
                    max_j=j;
                end
            end
        end
    end
    corners=[min_i,min_j;min_i,max_j;max_i,min_j;max_i,max_j];
end

