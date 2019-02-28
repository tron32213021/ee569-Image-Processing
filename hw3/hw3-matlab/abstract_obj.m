function G = abstract_obj(I,th)
    [height,width]=size(I);
    G=zeros(height,width);
    for i=1:height
        for j=1:width
            if I(i,j)<th-15 || I(i,j)>th+15
                G(i,j)=1;
            end
        end
    end
end

