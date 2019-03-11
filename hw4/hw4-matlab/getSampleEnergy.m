function [E] = getSampleEnergy(I,filters)
    I=reshape(I,[128,128]);
    I=I-mean(mean(I));
    [N,h,w]=size(filters);
    E=zeros(25,1);
    for n=1:N
        filter=reshape(filters(n,:,:),[h,w]);
        G=do_filter(I,filter);
        [height,width]=size(G);
        for i=1:height
            for j=1:width
                E(n)=E(n)+G(i,j)^2;
            end
        end
        E(n)=E(n)/(height*width);
    end
end

