function points = find_lonely_dots(I)
    points=[];
    [height,width]=size(I);
    for i=2:height-1
        for j=2:width-1
            if I(i,j)==0
                continue;
            end
            win=I(i-1:i+1,j-1:j+1);
            if win(1)+win(2)+win(3)+win(4)+win(6)+win(7)+win(8)+win(9)==0
                points=[points;[i,j]];
            end
        end
    end
end

