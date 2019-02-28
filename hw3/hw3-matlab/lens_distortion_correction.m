function G = lens_distortion_correction(I)
    [height,width]=size(I);
    c_x=(1+height)/2;
    c_y=(1+width)/2;
    R=max(c_x,c_y);
    G=zeros(height,width);
    for i=1:height
        for j=1:width
            x=i-c_x;
            y=j-c_y;
            p_new=sqrt(x^2+y^2);
            frac=warp_func(p_new,R);
            x_old=x*frac;
            y_old=y*frac;
            if (x_old+c_x<1 || x_old+c_x>=height || y_old+c_y<1 || y_old+c_y>=width)
                continue;
            end
            %[x_old+c_x,y_old+c_y]
            G(i,j)=getGrayValueByBilinear(I,[x_old+c_x,y_old+c_y]);
        end
    end
end

function v=warp_func(r,R)
    k1=-0.3536;
    k2=0.1730;
    k3=0;
    k=600;
    r=r/k;
    R=R/k;
    v=(1+k1*r^2+k2*r^4+k3*r^6)/(1+k1*R^2+k2*R^4+k3*R^6);
end