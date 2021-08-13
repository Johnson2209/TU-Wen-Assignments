function [ x ] = SOR( A,b,x0,kmax,w)

x = x0;
k = 1;
D = diag(diag(A));
L = -tril(A,-1);
U = -triu(A,1);
M = inv(D - w*L) *((1-w)*D + w*U);
N = w * inv(D - w*L) * b;

while k <= kmax
%    fprintf('Iteration %d \n',k)
    x = M*x + N; 
    k = k + 1;
end
end

