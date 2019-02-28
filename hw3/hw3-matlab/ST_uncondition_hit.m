function v = ST_uncondition_hit(I)
    v=0;
    if I(5)==0
        return;
    elseif spur(I)+L_cluster(I)+four_connected_offset(I)+spur_corner_cluster(I)+corner_cluster(I)+Tee_branch(I)+vee_branch(I)+diagonal_branch(I)>0
        v=1;
    end
end
function v=dot(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if(a+b+c+d+e+f+g+h)==0
        v=1;
    end
end

function v=spur(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if (a+b+c+d+e+f+g+h==1) &&(c==1 || a==1 || g==1 || e==1)
        v=1;
    end
end
function v=L_cluster(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if (a+b+c+d+e+f+g+h==2) && (c+e==2 || b+c==2 || a+b==2 || a+d==2 || d+f==2 || f+g==2 || g+h==2 || e+h==2)
        v=1;
    end    
end
function v=four_connected_offset(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if (a+b+c+d+e+f+g+h==3) && (c+b+d==3 || a+b+c==3 || b+e+h==3 || c+e+g==3)
        v=1;
    end  
end
function v=spur_corner_cluster(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if (a+d+g+h==0 && b+e>0 && c+f==2)
        v=1;
    end
    if (c+e+g+f==0 && b+d>0 && a+h==2)
        v=1;
    end   
    if (a+b+e+h==0 && d+g>0 && c+f==2)
        v=1;
    end
    if (c+b+d+f==0 && e+g>0 && a+h==2)
        v=1;
    end  
end
function v=corner_cluster(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if a+b+d==3
        v=1;
    end
end
function v=Tee_branch(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if b+d+e==3 && c+h+g==0
        v=1;
    end
    if b+d+e==3 && a+f+g==0
        v=1;
    end
    if g+d+e==3 && a+b+f==0
        v=1;
    end
    if b+d+e==3 && b+c+h==0
        v=1;
    end
    if b+d+g==3 && e+f+h==0
        v=1;
    end
    if b+d+g==3 && a+c+e==0
        v=1;
    end
    if b+e+g==3 && d+f+h==0
        v=1;
    end
    if b+e+g==3 && d+a+c==0
        v=1;
    end
end
function v=vee_branch(I)    
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);  
    if (a+c==2 && f+g+h>0)
        v=1;
    end
    if (a+f==2 && c+e+h>0)
        v=1;
    end
    if (f+h==2 && a+b+c>0)
        v=1;
    end
    if (c+h==2 && a+d+f>0)
        v=1;
    end
end
function v=diagonal_branch(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);  
    if(b+e+f==3&&c+d+g==0)
        v=1;
    end
    if(b+d+h==3&&a+e+g==0)
        v=1;
    end
    if(c+d+g==3&&b+e+f==0)
        v=1;
    end
    if(a+e+g==3&&b+d+h==0)
        v=1;
    end
end