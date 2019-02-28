function v = get_background_color(I)
    [height,width]=size(I);
    g=zeros(1,256);
    for i=1:height
        for j=1:width
            g(I(i,j)+1)=g(I(i,j)+1)+1;
        end
    end
    max=-1;v=0;
    for i=1:256
        if g(i)>max
            max=g(i);
            v=i-1;
        end
    end
end

