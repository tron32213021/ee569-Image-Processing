sub_I1=readraw("HW3_Images/lighthouse1.raw",256,256);
sub_I2=readraw("HW3_Images/lighthouse2.raw",256,256);
sub_I3=readraw("HW3_Images/lighthouse3.raw",256,256);
[edges1,corners1]=find_corners(sub_I1);
[edges2,corners2]=find_corners(sub_I2);
[edges3,corners3]=find_corners(sub_I3);
