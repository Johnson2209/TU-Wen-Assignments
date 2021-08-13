close all;
%%example 4 b)
figure(1)
n=1000;
h=1/n;

A=spdiags([-ones(n,1),2*ones(n,1),-ones(n,1)],[-1:1],n,n);

b=ones(n,1);

[X,FLAG,RELRES,ITER,RESVEC] = pcg(A,b,1E-10,n);


kappa=cond(A);
rate=(sqrt(kappa)-1)/(sqrt(kappa)+1);

semilogy([1:size(RESVEC)],RESVEC,[1:size(RESVEC)],2*rate.^[1:size(RESVEC)]*RESVEC(2),'linewidth',2)

RESVEC(end-2)

%%example 4 c
figure(2);


ns=[1024, 2048, 4096, 2*4096,4*4096,8*4096,16*4096];
mmax=size(ns,2);
niter=zeros(mmax,1);
resvecs=zeros(ns(end),mmax);
for m=[1:mmax]
    n = ns(m)
    A=spdiags([-ones(n,1),2*ones(n,1),-ones(n,1)],[-1:1],n,n);

    b=ones(size(A,1),1);

    uex=A \ b;
    
    [X,FLAG,RELRES,ITER,RESVEC] = pcg(A,b,1E-8,n);

    resvecs([1:size(RESVEC)],m)=RESVEC/norm(b,2);
    
    niter(m)=min(find(RESVEC/norm(b,2)<0.1));
end

loglog(1:ns(end),resvecs,'linewidth',2);
figure(3)
loglog(ns,niter,ns,ns,'linewidth',2)