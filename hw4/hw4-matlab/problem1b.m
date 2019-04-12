Laws_Filters;
image=readraw("./HW4_Images/comb.raw",510,510);
image=medfilt2(image,[5,5]);
filters_stack_res=zeros(510,510,25);
for n=1:25
    filter=reshape(filters(n,:,:),[5,5]);
    filters_stack_res(:,:,n)=do_filter(image,filter);
end
wn_size=21;
wn=fix(wn_size/2);
energy_vectors=zeros(510,510,25);
for i=1:510
    for j=1:510
        win=filters_stack_res(max(1,i-wn):min(510,i+wn),max(1,j-wn):min(510,j+wn),:);
        [h,w,~]=size(win);
        t=zeros(1,1,25);
        for x=1:h
            for y=1:w
                t=t+win(x,y,:).^2;
            end
        end
        t=t/(h*w);
        energy_vectors(i,j,:)=t;
    end
end

samples_t=reshape(energy_vectors,[510*510,25]);
samples=samples_t(:,2:25);
samples_norm=samples./std(samples(:,1));

C=cov(samples_norm);
[V,D]=eig(C);
coff=samples_norm*V(:,22:24);

idx=kmeans(samples_norm,7);
map_idx=uint8(reshape(idx,[510,510])*42);
imshow(map_idx);

