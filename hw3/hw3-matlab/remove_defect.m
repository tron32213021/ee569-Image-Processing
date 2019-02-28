function G = remove_defect(I,s)
    I=1-I;
    G=I;
    flag=1;
    while(flag==1)
        p=G;
        for i=1:s
            [p,~]=shrink_one_iteration(p);
        end
        points=find_lonely_dots(p);
        [n,~]=size(points);
        if n>0
            for i=1:n
                G(points(i,1),points(i,2))=0;
            end
        else
            flag=0;
        end
    end
    G=1-G;
end
   

