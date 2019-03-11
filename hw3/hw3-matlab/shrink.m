function G = shrink(I)
    pt=I;
    changes=1;
    i=0;
    while(changes==1)
        [pt,changes]=shrink_one_iteration(pt);
        i=i+1;
        %imshow(pt);
%         if i==20 || i==40
%             figure;imshow(pt);figure;
%         end
    end
    G=pt;
end

