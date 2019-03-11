function G = thin(I)
    pt=I;
    changes=1;
    i=0;
    while(changes==1)
        [pt,changes]=thin_one_iteration(pt);
        i=i+1;
%         if i==20 || i==40
%             figure;imshow(pt);figure;
%         end
    end
    G=pt;
end

