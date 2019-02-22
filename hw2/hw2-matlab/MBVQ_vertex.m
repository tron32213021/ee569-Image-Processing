%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = MBVQ_vertex(P,string)
    P=double(P);
    K=[0,0,0];R=[255,0,0];G=[0,255,0];B=[0,0,255];
    C=[0,255,255];M=[255,0,255];Y=[255,255,0];W=[255,255,255];
    if string=="cmyw"
        Q=[C;M;Y;W];
    elseif string=="mygc"
        Q=[M;Y;G;C];
    elseif string=="rgmy"
        Q=[R;G;M;Y];
    elseif string=="krgb"
        Q=[K;R;G;B];
    elseif string=="rgbm"
        Q=[R;G;B;M];
    elseif string=="cmgb"
        Q=[C;M;G;B];
    end
    d=[P(1)-Q(1,1),P(2)-Q(1,2),P(3)-Q(1,3)];
    G=Q(1,:);
    min_d=d(1)^2+d(2)^2+d(3)^2;
    for i=2:4
        d=[P(1)-Q(i,1),P(2)-Q(i,2),P(3)-Q(i,3)];
        if min_d>d(1)^2+d(2)^2+d(3)^2
            min_d=d(1)^2+d(2)^2+d(3)^2;
            G=Q(i,:);
        end
    end
end

