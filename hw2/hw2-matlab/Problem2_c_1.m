%copyright: ZhenyeJiang, zhenyeji@usc.edu
clear;
Floyd3=[0,0,7;3,5,1]/16;
bird_path="HW2_images/bird.raw";
bird_rgb=readraw(bird_path,375,500,3);
figure;imshow(bird_rgb);
bird_cmy=convertRGB2CMY(bird_rgb);
[c1,c2,c3]=separate_3channels(bird_cmy);
c1_diffusion=uint8(halftone_by_err(c1,Floyd3));
c2_diffusion=uint8(halftone_by_err(c2,Floyd3));
c3_diffusion=uint8(halftone_by_err(c3,Floyd3));
bird_cmy_diffusion=uint8(fusion_3channel(c1_diffusion,c2_diffusion,c3_diffusion));
bird_rgb_diffusion=uint8(convertRGB2CMY(bird_cmy_diffusion));
figure;imshow(bird_rgb_diffusion);