%copyright: ZhenyeJiang, zhenyeji@usc.edu
function threshold = generate_threshold_matrix(I)
    [N,~]=size(I);
    threshold=zeros(N,N);
    for i=1:N
        for j=1:N
            threshold(i,j)=(I(i,j)+0.5)/(N*N)*255;
        end
    end
end

