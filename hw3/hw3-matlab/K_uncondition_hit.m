function v = K_uncondition_hit(I)
    v=0;
    if I(5)==0
        return;
    elseif spur(I)+L_cluster(I)+four_connection(I)+corner_cluster(I)+Tee_branch(I)+Vee_branch(I)+diagonal_branch(I)>0
        v=1;
    end
end

function v=spur(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if(a+b+c+d+e+f+g+h==1 && (a==1 || c==1 || f==1 || h==1))
        v=1;
    end
end
function v=four_connection(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if(a+b+c+d+e+f+g+h==1 && (b==1 || d==1 || e==1 || g==1))
        v=1;
    end
end
function v=L_cluster(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if(a+b+c+d+e+f+g+h==2 && (b+e==2 || b+d==2 || d+g==2 || g+e==2))
        v=1;
    end
end
function v=corner_cluster(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if a+b+d==3 || e+g+h==3
        v=1;
    end
end
function v=Tee_branch(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if b+d+e==3 || b+d+g==3 || d+e+g==3 || b+e+g==3
        v=1;
    end
end
function v=Vee_branch(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if(a+c==2&&f+g+h>0)
        v=1;
    end
    if(a+f==2&&c+e+h>0)
        v=1;
    end
    if(f+h==2&&a+b+c>0)
        v=1;
    end
    if(c+h==2&&a+d+f>0)
        v=1;
    end
end
function v=diagonal_branch(I)
    v=0;
    a=I(1);b=I(2);c=I(3);
    d=I(4);       e=I(6);
    f=I(7);g=I(8);h=I(9);
    if(b+e+f==3 && c+d+g==0)
        v=1;
    end
    if(b+d+h==3 && a+e+g==0)
        v=1;
    end
    if(c+d+g==3 && b+e+f==0)
        v=1;
    end
    if(a+e+g==3 && b+d+h==0)
        v=1;
    end
end