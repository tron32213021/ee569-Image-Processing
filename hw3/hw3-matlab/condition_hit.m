function b = condition_hit(masks,v)
    b=0;
    lenv=sum(v);
    if(lenv==0)
        return;
    end
    lenmasks=sum(masks,1);
    L=lenv*lenmasks;
    x=((v*masks).^2==L);
    if sum(x)>0
        b=1;
    end
end

