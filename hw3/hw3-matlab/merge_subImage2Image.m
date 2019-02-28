function G = merge_subImage2Image(I,sub_I,I_co,sub_co)
    G=I;
    M1=get_TranformMatrix(sub_co(1:3,:),I_co(1:3,:));
    M2=get_TranformMatrix(sub_co(2:4,:),I_co(2:4,:));
    for i=I_co(1,1):I_co(3,1)
        for j=I_co(1,2):fix(I_co(2,2)-(i-I_co(1,1))*(I_co(2,2)-I_co(1,2))/(I_co(3,1)-I_co(1,1)))
            co_t=M1*[i;j;1];
            G(i,j)=getGrayValueByBilinear(sub_I,co_t(1:2));
        end
    end
    for i=I_co(2,1):I_co(3,1)
        for j=fix(I_co(2,2)-(i-I_co(1,1))*(I_co(2,2)-I_co(1,2))/(I_co(3,1)-I_co(1,1)))+1:I_co(2,2)
            co_t=M2*[i;j;1];
            G(i,j)=getGrayValueByBilinear(sub_I,co_t);
        end
    end
end


