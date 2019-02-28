function [num,C] = myClasses(points,Size)
    height=Size(1);width=Size(2);
    C=[height/8,width/6;
        height/8,width*3/6;
        height/8,width*5/6;
        height*3/8,width/6;
        height*3/8,width*3/6;
        height*3/8,width*5/6;
        height*5/8,width/6;
        height*5/8,width*3/6;
        height*5/8,width*5/6;
        height*7/8,width/3;
        height*7/8,width*2/3];
    [N,~]=size(points);
    for kkk=1:5
        belongs=zeros(N,1);
        for i=1:N
            belongs(i)=1;dis=10^10;
            for j=1:11
                if norm(C(j,:)-points(i,:))<dis
                    dis=norm(C(j,:)-points(i,:));
                    belongs(i)=j;
                end
            end
        end
        num=zeros(11,1);
        for i=1:N
            num(belongs(i))=num(belongs(i))+1;
        end
        new_C=zeros(11,2);
        for i=1:N
            new_C(belongs(i),:)=new_C(belongs(i),:)+points(i,:);
        end
        new_C=new_C./num;
        C=new_C;
    end
end

