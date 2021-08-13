A = gallery('poisson',3);
b = [1;1;1;1;1;1;1;1;1];
x = A\b;  %exact solution

x0 = [0;0;0;0;0;0;0;0;0];
w = 1:0.1:2;
n = length(w);
error = zeros(1,n);
for i = 1:n
  xS = SOR(A,b,x0,5,w(i));
  error(i) = norm(x-xS);
end
semilogy(w,error)

kmax = 2:2:20;
m = length(kmax);
errors = zeros(3,m);
for j = 1:m;
  xJ = Jacobi(A,b,x0,kmax(j));
  xG = GaussSeidel(A,b,x0,kmax(j));
  xS = SOR(A,b,x0,kmax(j),1.25);
  errors(:,j) = [norm(x-xJ);norm(x-xG);norm(x-xS)];  
end
figure()
semilogy(kmax,errors(1,:))  %Jacobi plot
hold on
semilogy(kmax,errors(2,:))  %GaussSeidel plot
semilogy(kmax,errors(3,:))  %SOR plot
legend()