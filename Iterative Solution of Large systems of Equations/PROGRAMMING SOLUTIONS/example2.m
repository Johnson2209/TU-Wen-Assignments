n=100;

A=gallery('poisson',n);
b=rand(size(A,1),1);%ones(size(A,1),1);

x0=zeros(size(b));
rese=zeros(4,10);

xex=A \ b;

for m=1:10
    maxit=round(2.^m)
    [xc,FLAG,RELRES,ITER,RESVEC]=pcg(A,b,1E-16,maxit,[],[],x0);
    resc=A*xc-b;
    errc=xex-xc;
    rese(m,1)=norm(resc,2)/norm(b,2);
    rese(m,2)=sqrt(errc'*A*errc)/sqrt(xex'*A*xex);

    [xg,FLAG,RELRES,ITER,RESVEC2]=gmres(A,b,maxit,1E-16,1,[],[],x0);
    resg=A*xg-b;
    errg=xex-xg;
    rese(m,3)=norm(resg,2)/norm(b,2);
    rese(m,4)=sqrt(errg'*A*errg)/sqrt(xex'*A*xex);
    
    
    [xs,rs]=steepest(x0,A,b,maxit);
    ress=A*xs-b;
    errs=xex-xs;
    rese(m,5)=norm(ress,2)/norm(b,2);
    rese(m,6)=sqrt(errs'*A*errs)/sqrt(xex'*A*xex);
    
    
    [xJC,resJC]=jacobi(A,b,x0,maxit);
    resJ=A*xJC-b;
    errs=xex-xJC;
    rese(m,7)=norm(resJ,2)/norm(b,2);
    rese(m,8)=sqrt(errs'*A*errs)/sqrt(xex'*A*xex);
    
    [xGS,resGS]=GS(A,b,x0,maxit);
    resG=A*xGS-b;
    errs=xex-xGS;
    rese(m,9)=norm(resG,2)/norm(b,2);
    rese(m,10)=sqrt(errs'*A*errs)/sqrt(xex'*A*xex);
end

figure(1)
loglog(2.^[1:m],rese(:,1),2.^[1:m],rese(:,3),2.^[1:m],rese(:,5),2.^[1:m],rese(:,7),2.^[1:m],rese(:,9),'linewidth',2)
legend('cg','gmres','steepest','jacobi','GS')
title('residual norm')

figure(2)
loglog(2.^[1:m],rese(:,2),2.^[1:m],rese(:,4),2.^[1:m],rese(:,6),2.^[1:m],rese(:,8),2.^[1:m],rese(:,10),'linewidth',2)
legend('cg','gmres','steepest','jacobi','GS')
title('energy norm')

figure(3)
loglog([1:size(RESVEC,1)],RESVEC,[1:size(RESVEC2)],RESVEC2,'linewidth',2)
title('Resvec')

figure(4)
loglog(2.^[1:m],rese(:,5),2.^[1:m],rese(:,7),2.^[1:m],rese(:,9),'linewidth',2)
legend('steepest','jacobi','GS')
title('residual norm')

figure(5)
loglog(2.^[1:m],rese(:,6),2.^[1:m],rese(:,8),2.^[1:m],rese(:,10),'linewidth',2)
legend('steepest','jacobi','GS')
title('energy norm')

rese(8,2)-rese(8,4)




%----------------------------
function [x,resvec] = jacobi(A,b,x,iter)
%input: matrix A, rhs b, initial vector x
%output: sequence of residual vectors for Jacobi method 
resvec = zeros(iter,1); 
DD = diag(A); 
N = size(A,1); 
D = spdiags(DD,0,N,N); 
for i=1:iter
  r = b - A*x; 
  resvec(i) = norm(r); 
  x = x + D\r; 
end 
end

%----------------------------
function [x,resvec] = GS(A,b,x,iter)
%input: matrix A, rhs b, initial vector x
%output: sequence of residual vectors for Gauss-Seidel
resvec = zeros(iter,1); 
L=  tril(A,-1);  %strictly lower part 
R=  triu(A,1);   %strictly upper part 
DD = diag(A); 
N = size(A,1); 
D = spdiags(DD,0,N,N); 
for i=1:iter
 r = b - A*x; 
 resvec(i) = norm(r); 
 x = x + (L+D)\r; 
end 
end


function [x,r] = steepest(x,A,b,maxit)
for k=1:maxit
   r = b-A*x;
   alpha = r'*r/((A*r)'*r);
   x = x+alpha*r;
end
end
