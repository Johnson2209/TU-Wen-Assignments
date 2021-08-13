%% Parameters
N = 5;      %size of matrix
max_iter = 25;     % maximum number of iterations
A = gallery('poisson',N);
b = ones(N*N,1);
%% Steepest Descent
x = zeros(N*N,max_iter);
x(:,1) = 1;     %initial condition is 1 
r = zeros(N*N,max_iter);
res = zeros(1,max_iter);
for k = 1:max_iter
    r(:,k) = b - A*x(:,k);
    res(k) = norm(r(:,k),2);
    alpha = dot(r(:,k),r(:,k))/dot(A*r(:,k), r(:,k));
    x(:,k+1) = x(:,k) + alpha*r(:,k);
end
%% PCG
[x2,flag2,relres2,iter2,resvec2] = pcg(A,b,[],max_iter);
assert(flag2==0)
%% GMRES
[x3,flag3,relres3,iter3,resvec3] = gmres(A,b,[],[],max_iter);
assert(flag2==0)
%% Plot
clf
figure(1)
loglog(res,'r','LineWidth',1.2)
hold on
loglog(resvec2,'LineWidth',1.2)
loglog(resvec3,'g--','LineWidth',1.2)
xlabel('Iterations')
ylabel('Residuals')
title('Residual plots for 3 methods')
legend({'SD','PCG','GMRES'})

%% Energy norm error
xstar = A\b;
[x2] = pcg(A,b,[],5);
[x3] = gmres(A,b,[],[],5);
e_pcg = dot(A*(x2-xstar),x2-xstar)
e_gmres = dot(A*(x3-xstar),x3-xstar)