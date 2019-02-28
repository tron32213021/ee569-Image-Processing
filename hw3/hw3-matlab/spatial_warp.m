function G = spatial_warp(I,p)
    [height,width]=size(I);
   
    c_x=(1+height)/2;
    c_y=(1+width)/2;
    c=[c_x,c_y];
    G=zeros(height,width);
    p1=[1,1]-c;p2=[1,width]-c;p3=[height,1]-c;p4=[height,width]-c;
    p5=[height*p+1-p,width*p+1-p]-c;p6=[height*p+1-p,width*(1-p)+p]-c;p7=[height*(1-p)+p,width*p+1-p]-c;p8=[height*(1-p)+p,width*(1-p)+p]-c;
    p9=[height*p+1-p,width/2+1/2]-c;p10=[height/2+1/2,width*p+1-p]-c;p11=[height/2+1/2,width*(1-p)+p]-c;p12=[height*(1-p)+p,width/2+1/2]-c;
    p13=[0,0];
    p14=[1,width/2+1/2]-c;p15=[height/2+1/2,1]-c;p16=[height/2+1/2,width]-c;p17=[height,width/2+1/2]-c;
    M1=[p2',p16',p4',p6',p8',p13']/builtMat(p2,p11,p4,p6,p8,p13);
    M2=[p1',p15',p3',p5',p7',p13']/builtMat(p1,p10,p3,p5,p7,p13);
    M3=[p1',p14',p2',p5',p6',p13']/builtMat(p1,p9,p2,p5,p6,p13);
    M4=[p3',p17',p4',p7',p8',p13']/builtMat(p3,p12,p4,p7,p8,p13);
    for i=1:height
        for j=1:width
            x=i-c_x;
            y=j-c_y;
            t=[1;x;y;x^2;x*y;y^2];
            if (y>=abs(x))
                tt=M1*t;
                x_old=tt(1);y_old=tt(2);
            elseif (y<=-abs(x))
                tt=M2*t;
                x_old=tt(1);y_old=tt(2);               
            elseif (y>x && y<-x)
                tt=M3*t;
                x_old=tt(1);y_old=tt(2);            
            else
                tt=M4*t;
                x_old=tt(1);y_old=tt(2);            
            end
            if (x_old+c_x<1 || x_old+c_x>=height || y_old+c_y<1 || y_old+c_y>=width)
                continue;
            end
            
            G(i,j)=getGrayValueByBilinear(I,[x_old+c_x,y_old+c_y]);
        end
    end
end


function M=builtMat(p0,p1,p2,p3,p4,p5)
    t1=[p0(1),p1(1),p2(1),p3(1),p4(1),p5(1)];
    t2=[p0(2),p1(2),p2(2),p3(2),p4(2),p5(2)];
    M=[1,1,1,1,1,1;
        t1;
        t2;
        t1.^2;
        t1.*t2;
        t2.^2];
end