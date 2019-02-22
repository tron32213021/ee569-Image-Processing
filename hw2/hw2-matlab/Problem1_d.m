%copyright: ZhenyeJiang, zhenyeji@usc.edu
clear;
pig=imread('HW2_images/Pig.jpg');
tiger=imread('HW2_images/Tiger.jpg');

edge=SE_edge_dectector(tiger);
cd ..;
ttt=load('HW2_images/Tiger.mat');
for i=1:5
    groundTruth={ttt.groundTruth{i}};
    save('t.mat','groundTruth');
    [thrs,cntR,sumR,cntP,sumP,V]=edgesEvalImg( edge, 't.mat',{ 'thrs',11});
    tables=zeros(11,3);
    tables(:,1)=cntP./sumP;
    tables(:,2)=cntR./sumR;
    tables(:,3)=2.*tables(:,1).*tables(:,2)./(tables(:,1)+tables(:,2));

end
