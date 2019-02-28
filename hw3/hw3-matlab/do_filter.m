%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = do_filter( I,filter,weight )
    I=double(I);
    [height,width]=size(I);
    [h,w]=size(filter);
    G=zeros(height,width);

    for i=1:height
        for j=1:width
            t=0;
            for x=1:h
                for y=1:w
                    t=t+getPixel(I,i-fix(h/2)+x-1,j-fix(w/2)+y-1)*getPixel(filter,x,y);
                end
            end
            G(i,j)=t/weight;
        end
    end
end

