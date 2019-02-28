function v = getGrayValueByBilinear(sub_I,p)
    x=p(1);y=p(2);
    a=fix(x);
    b=a+1;
    c=fix(y);
    d=c+1;
    %[x,y,a,b,c,d]
    v=sub_I(a,c)*(d-y)*(b-x)+sub_I(a,d)*(b-x)*(y-c)+sub_I(b,c)*(x-a)*(d-y)+sub_I(b,d)*(x-a)*(y-c);
    v=uint8(v);
end

