n=1000

A=spdiags([ones(n,1),ones(n,1)],[0,1],n,n);
%A=spdiags([ones(n,1)],[-1],n,n);

%A(1,end)=1;
%xA(1,1)=0;
%b=A \ ones(n,1);
%b
%b(1)=1;
b=ones(n,1)


%b(end)=1;
%b(1)=1;
%b=b*n

errs=n;
%for nmax=1:n
[y,flag,relres,iter,resvec]=gmres(A,b,n,1E-16,n);

resvec
loglog([1:size(resvec)],resvec,'linewidth',2)

    
    