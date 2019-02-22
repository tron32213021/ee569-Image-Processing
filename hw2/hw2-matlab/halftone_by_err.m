%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = halftone_by_err(I,F)
    [height,width]=size(I);
    [N,~]=size(F);
    direction=1;
    j=0;
    G=double(I);
    for i=1:height
        j=j+direction;
        while(j>0 && j<=width)
            if G(i,j)<128
                err=G(i,j);
                G(i,j)=0;
            else
                err=G(i,j)-255;
                G(i,j)=255;
            end
            center_x=1;center_y=N;
            for x=0:N-1
                for y=-(N-1):(N-1)
                    if F(center_x+x,center_y+y*direction)==0 || (j+y<1) || (j+y>width) || (i+x>height)
                        continue;
                    end
                    G(i+x,j+y)=G(i+x,j+y)+err*F(center_x+x,center_y+y*direction);
                end
            end
            j=j+direction;
        end
        direction=-direction;
    end
end

