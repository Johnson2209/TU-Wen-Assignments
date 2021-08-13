function [ x ] = Jacobi( A,b,x0,kmax)

x = x0;
k = 1;
D = diag(diag(A));
L = -tril(A,-1);
U = -triu(A,1);
M = inv(D)*(L+U);
N = inv(D)*b;

while k <= kmax
    x = M*x + N;
    k = k + 1;
end
end

