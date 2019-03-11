K=[1,4,6,4,1;
    -1,-2,0,2,1;
    -1,0,2,0,-1;
    -1,2,0,-2,1;
    1,-4,6,-4,1];
[N,~]=size(K);
filters=zeros(N*N,N,N);
for i=1:N
    for j=1:N
        filters((i-1)*N+j,:,:)=K(i,:)'*K(j,:);
    end
end