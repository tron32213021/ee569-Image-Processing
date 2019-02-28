Problem1_a_2;
Problem1_a_4;
G=I;
for i=1:160
    for j=1:160
        G(part1_corners(1,1)+i,part1_corners(1,2)+j)=sub1(i+1,j+1);
    end
end
for i=1:160
    for j=1:160
        G(part2_corners(1,1)+i,part2_corners(1,2)+j)=sub2(i+2,j+1);
    end
end
for i=1:160
    for j=1:160
        G(part3_corners(1,1)+i,part3_corners(1,2)+j)=sub3(i+1,j+2);
    end
end
imshow(G);