function [edges,corners] = find_corners(I)
    corners=[];
    I(I<255)=0;
    filter=ones(5,5)*-1;
    filter(3,3)=24;
    edges=edge(I,'canny',[0.2,0.8]);
    imshow(edges);
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
    for i=[min_i,max_i]
        s=[0,0];n=0;
        for j=min_j:max_j
            if edges(i,j)
                s=s+[i,j];
                n=n+1;
            end
        end
        corners=[corners;fix(s/n)];
    end
    for j=[min_j,max_j]
        s=[0,0];n=0;
        for i=min_i+1:max_i-1
            if edges(i,j)
                s=s+[i,j];
                n=n+1;
            end
        end
        corners=[corners;fix(s/n)];
    end
end

