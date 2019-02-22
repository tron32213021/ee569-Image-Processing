%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = MBVQ(I,F)
    I=double(I);
    [height,width,channel]=size(I);
    [N,~]=size(F);
    error=zeros(height,width,channel);
    direction=1;
    j=0;
    G=double(I);
    for i=1:height
        j=j+direction;
        while(j>0 && j<=width)
            string=MBVQ_string(I(i,j,:));
            P=MBVQ_vertex([I(i,j,1)+error(i,j,1),I(i,j,2)+error(i,j,2),I(i,j,3)+error(i,j,3)],string);
            err=[I(i,j,1)+error(i,j,1)-P(1),I(i,j,2)+error(i,j,2)-P(2),I(i,j,3)+error(i,j,3)-P(3)];
            G(i,j,1)=P(1);G(i,j,2)=P(2);G(i,j,3)=P(3);
            center_x=1;center_y=N;
            for x=0:N-1
                for y=-(N-1):(N-1)
                    if F(center_x+x,center_y+y*direction)==0 || (j+y<1) || (j+y>width) || (i+x>height)
                        continue;
                    end
                    error(i+x,j+y,1)=error(i+x,j+y,1)+err(1)*F(center_x+x,center_y+y*direction);
                    error(i+x,j+y,2)=error(i+x,j+y,2)+err(2)*F(center_x+x,center_y+y*direction);
                    error(i+x,j+y,3)=error(i+x,j+y,3)+err(3)*F(center_x+x,center_y+y*direction);
                end
            end
            j=j+direction;
        end
        direction=-direction;
    end

end

