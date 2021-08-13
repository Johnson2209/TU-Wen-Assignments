n = 1000;      %size of matrix ( use 5 for demo)
max_iter = 1000;
A = gallery('tridiag',n,0,1,1);
b = ones(n,1);
[x,flag,relres,iter,resvec] = gmres(A,b,[],1e-16,max_iter);
% assert(flag==0);
clf
figure(1)
loglog(resvec,'r','LineWidth',2)
xlabel('Iterations')
ylabel('Residual')
title('GMRES Plot')
r = norm(A*x-b,2)