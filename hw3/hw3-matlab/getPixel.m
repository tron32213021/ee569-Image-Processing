%copyright: ZhenyeJiang, zhenyeji@usc.edu
function value = getPixel( I,x,y,z )
    shape=size(I);
    height=shape(1);
    width=shape(2);
    channel=1;
    if length(shape)>2
        channel=shape(3);
    end
    if x<1
        x=2*1-x;
    end
    if x>height
        x=2*height-x;
    end
    if y<1
        y=2-y;
    end
    if y>width
        y=2*width-y;
    end
    if channel>1
        value=I(x,y,z);
    else
        value=I(x,y);
    end
end

