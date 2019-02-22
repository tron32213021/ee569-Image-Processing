%copyright: ZhenyeJiang, zhenyeji@usc.edu
clear;
Floyd3=[0,0,7;3,5,1]/16;
bird_path="HW2_images/bird.raw";
bird_rgb=readraw(bird_path,375,500,3);
figure;imshow(bird_rgb);
G=MBVQ(bird_rgb,Floyd3);
figure;imshow(uint8(G));