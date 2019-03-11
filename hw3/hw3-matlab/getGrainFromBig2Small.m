function [points_sorted,s] = getGrainFromBig2Small(I,points,C,n)
    areas=bwlabel(I,8);
    [N,~]=size(points);
    pt=[];
    for i=1:N
        dis=99999;class=1;
        for j=1:11
            if norm(points(i,:)-C(j,:))<dis
                dis=norm(points(i,:)-C(j,:));
                class=j;
            end
        end
        if class==n
            pt=[pt;points(i,:)];
        end
    end
    [N,~]=size(pt);
    s=zeros(N,1);
    for i=1:N
        s(i)=sum(sum(areas==areas(pt(i,1),pt(i,2))));
    end
    [~,ind]=sort(s,'descend');
    points_sorted=pt(ind,:);
end

