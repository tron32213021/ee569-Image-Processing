function G = max_filter(I)
    [height,width]=size(I);
    G=zeros(height,width);
    for i=2:height-1
        for j=2:width-1
            win=I(i-1:i+1,j-1:j+1);
            G(i,j)=max(max(win));
        end
    end
end

