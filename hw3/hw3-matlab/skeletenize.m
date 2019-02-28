function G = skeletenize(I)
    pt=I;
    changes=1;
    while(changes==1)
        [pt,changes]=Skel_one_iteration(pt);
    end
    G=pt;
end

