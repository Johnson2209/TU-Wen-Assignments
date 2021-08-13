function [ x ] = GaussSeidel( A,b,x0,kmax )
x = x0;
k = 1;
D = diag(diag(A));
L = -tril(A,-1);
U = -triu(A,1);
% dl = inv(D-L);
M = (D-L)\U;
N = (D-L)\b;

while k <= kmax
    x = M*x + N;
    k = k + 1;
end
end

