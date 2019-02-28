function G = shrink(I)
    pt=I;
    changes=1;
    while(changes==1)
        [pt,changes]=shrink_one_iteration(pt);
    end
    G=pt;
end

