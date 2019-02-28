function GG = skeletenize(I)
    pt=I;
    changes=1;
    while(changes==1)
        [pt,changes]=Skel_one_iteration(pt);
    end
    GG=pt;
    [height,width]=size(GG);
    G=zeros(height,width);
    for i=2:height-1
        for j=2:width-1
            win=GG(i-1:i+1,j-1:j+1);
            G(i,j)=bridging(win);
        end
    end
end

function v=bridging(I)
    
    x3=I(1);x2=I(2);x1=I(3);
    x4=I(4);x=I(5);x0=I(6);
    x5=I(7);x6=I(8);x7=I(9);
    L1=(1-x)*(1-x0)*x1*(1-x2)*x3*(1-x4)*(1-x5)*(1-x6)*(1-x7);
    L2=(1-x)*(1-x0)*(1-x1)*(1-x2)*x3*(1-x4)*x5*(1-x6)*(1-x7);
    L3=(1-x)*(1-x0)*(1-x1)*(1-x2)*(1-x3)*(1-x4)*x5*(1-x6)*x7;
    L4=(1-x)*(1-x0)*x1*(1-x2)*(1-x3)*(1-x4)*(1-x5)*(1-x6)*x7;
    PQ=logical(L1+L2+L3+L4);
    P1=logical((1-x2)*(1-x6)*(x3+x4+x5)*(x0+x1+x7)*(1-PQ));
    P2=logical((1-x0)*(1-x4)*(x1+x2+x3)*(x5+x6+x7)*(1-PQ));
    P3=logical((1-x0)*(1-x6)*x7*(x2+x3+x4));
    P4=logical((1-x0)*(1-x2)*x1*(x4+x5+x6));
    P5=logical((1-x2)*(1-x4)*x3*(x0+x6+x7));
    P6=logical((1-x4)*(1-x6)*x5*(x0+x1+x2));
    v=logical(x+P1+P2+P3+P4+P5+P6);
    
end
