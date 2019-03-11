function [G,changes] = thin_one_iteration(I)
    changes=0;
    conditional_masks;
    masks=[TK4,STK4,ST5,ST6,STK6,STK7,STK8,STK9,STK10];
    [height,width]=size(I);
    T=zeros(height,width);
    for i=2:height-1
        for j=2:width-1
            if I(i,j)==0
                continue;
            end
            win=I(i-1:i+1,j-1:j+1);
            v=[win(6),win(3),win(2),win(1),win(4),win(7),win(8),win(9)];
            if condition_hit(masks,v)==1
                T(i,j)=1;
            end
        end
    end
    %imshow(T);
    G=I;
    for i=2:height-1
        for j=2:width-1
            if T(i,j)==0
                continue;
            end
            win=T(i-1:i+1,j-1:j+1);
            if(ST_uncondition_hit(win)==0)
                G(i,j)=0;
                changes=1;
            end
        end
    end
end

