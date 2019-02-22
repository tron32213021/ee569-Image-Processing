%copyright: ZhenyeJiang, zhenyeji@usc.edu
clear;
bridge_path="HW2_images/bridge.raw";
bridge_gray=readraw(bridge_path,400,600);
Floyd3=[0,0,7;3,5,1]/16;
Jarvis5=[0,0,0,7,5;3,5,7,5,3;1,3,5,3,1]/48;
Stucki5=[0,0,0,8,4;2,4,8,4,2;1,2,4,2,1]/42;
G1=uint8(halftone_by_err(bridge_gray,Floyd3));
G2=uint8(halftone_by_err(bridge_gray,Jarvis5));
G3=uint8(halftone_by_err(bridge_gray,Stucki5));
figure;imshow(G1);
figure;imshow(G2);
figure;imshow(G3);