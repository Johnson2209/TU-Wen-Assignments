%Group 11: Johnson Oyero and Yaw Owusu-Agyemang
% Programming with Matlab

% Our test matrix
A = [3,5;7,6];

%det(A) computes the determinant of square matrix A.
D = det(A);

%trace(A) computes the sum of the diagonal elements of the matrix A
T = trace(A);

R = rank(A);
%{rank(A) returns the rank of matrix A. 
% rank(A,tol) specifies a 
%different tolerance to use in the rank computation. The rank is
%computed as the number of singular values of A that are larger than tol

I = inv(A);
% Y = inv(X) computes the inverse of square matrix X.
% X^(-1) is equivalent to inv(X).
% x = A\b is computed differently than x = inv(A)*b and is recommended for solving systems of linear equations.

C = cond(A);
%C = cond(A) returns the 2-norm condition number for inversion, equal to the ratio of the largest singular value of A to the smallest
%C = cond(A,p) returns the p-norm condition number, where p can be 1, 2, Inf, or 'fro'

P = pinv(A);
%B = pinv(A) returns the Moore-Penrose Pseudoinverse of matrix A
%B = pinv(A,tol) specifies a value for the tolerance. pinv treats singular values of A that are smaller than the tolerance as zero.
%Moore Penrose conditions:
%1. AA^+A = A
%2. A^+AA^+ = A^+
%3. (AA^+)^* = AA^+
%4. (A^+A)= A^+A

% To display the results
fprintf("The test matrix is \n");disp(A)
fprintf("The determinant of the matrix A is %.2f\n",D)
fprintf("The trace of the matrix A is %.2f\n",T)
fprintf("The rank of the matrix A is %.2f\n",R)
fprintf("The inverse of the matrix A is \n"); disp(I)
fprintf("The 2-norm condition number of the matrix A is %.2f\n",C)
fprintf("The Moore-Penrose Pseudoinverse of the matrix A is \n");disp(P)