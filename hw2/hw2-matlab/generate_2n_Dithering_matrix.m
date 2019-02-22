%copyright: ZhenyeJiang, zhenyeji@usc.edu
function G = generate_2n_Dithering_matrix(I)
    [N,~]=size(I);
    G=zeros(2*N,2*N);
    for i=1:2*N
        for j=1:2*N
            if (fix((i-1)/N)==0 &&  fix((j-1)/N)==0)
                t=1;
            elseif (fix((i-1)/N)==1 &&  fix((j-1)/N)==0)
                t=3;
            elseif (fix((i-1)/N)==1 &&  fix((j-1)/N)==1)
                t=2;
            else
                t=0;
            end
            G(i,j)=I(mod(i-1,N)+1,mod(j-1,N)+1)*4+t;
        end
    end
end

