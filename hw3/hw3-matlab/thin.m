function G = thin(I)
    pt=I;
    changes=1;
    while(changes==1)
        [pt,changes]=thin_one_iteration(pt);
    end
    G=pt;
end

