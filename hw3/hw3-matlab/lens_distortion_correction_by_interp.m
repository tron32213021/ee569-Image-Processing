function G = lens_distortion_correction_by_interp(I)
    [height,width]=size(I);
    c_x=(1+height)/2;
    c_y=(1+width)/2;
    step=10;
    x_t=1-c_x:step:height-c_x;
    y_t=1-c_y:step:height-c_y;
    Z=[];
    Data=[];
    for i=x_t
        for j=y_t
            Data=[Data;[1,i,j]];
            [xd,yd]=f(i,j);
            Z=[Z;[xd,yd]];
        end
    end
    M=Z'/Data';
    G=zeros(height,width);
    for i=1:height
        for j=1:width
            p=M*[1;i-c_x;j-c_y];
            xd=p(1);yd=p(2);
            if (xd+c_x<1 || xd+c_x>=height || yd+c_y<1 || yd+c_y>=width)
                continue;
            end   
            G(i,j)=getGrayValueByBilinear(I,[xd+c_x,yd+c_y]);
        end
    end
    G=uint8(G);
end

function [xd,yd]=f(x,y)
    k1=-0.3536;
    k2=0.1730;
    k3=0;
    k=600;
    r=sqrt(x^2+y^2)/k;
    xd=x*(1+k1*r^2+k2*r^4+k3*r^6);
    yd=y*(1+k1*r^2+k2*r^4+k3*r^6);
    
end
