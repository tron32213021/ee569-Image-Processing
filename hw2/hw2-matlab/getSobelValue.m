%copyright: ZhenyeJiang, zhenyeji@usc.edu
function value = getSobelValue( sobel_x,sobel_y )
    [X,Y]=size(sobel_x);
    value=zeros(X,Y);
    for i=1:X
        for j=1:Y
            value(i,j)=sqrt(sobel_x(i,j)^2+sobel_y(i,j)^2);
        end
    end
end

