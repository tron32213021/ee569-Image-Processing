clear;
sub_I1=readraw("HW3_Images/lighthouse1.raw",256,256);
sub_I2=readraw("HW3_Images/lighthouse2.raw",256,256);
sub_I3=readraw("HW3_Images/lighthouse3.raw",256,256);
sub_co1=[184,79;81,118;224,182;120,222];
sub_co2=[213,108;102,16;119,219;9,126];
sub_co3=[4,45;45,252;211,4;252,211];
I_co=[1,1;1,162;162,1;162,162];
sub=zeros(160,160);
sub1=uint8(merge_subImage2Image(sub,sub_I1,I_co,sub_co1));
sub2=uint8(merge_subImage2Image(sub,sub_I2,I_co,sub_co2));
sub3=uint8(merge_subImage2Image(sub,sub_I3,I_co,sub_co3));