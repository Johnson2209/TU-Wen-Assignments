%% Parameters
y = @(t) sqrt(1+t.^2);
f = @(t) t./y(t);
a = [0 0 -1 1];   %a_m / a(end) must be 1
B = (1/12)*[5 -16 23 0];  %B_m / B(end) must be 0
T = 1;

%% Simulation and Plot
h = 2.^-(1:5);
k = length(h);
err_l = zeros(1,k);
err_expEu = zeros(1,k);
err_modEu = zeros(1,k);

for i = 1:k
    ini_vals1 = y([0 h(i) 2*h(i)]);
    ini_vals2 = explicitEuler(f,h(i),0,1);
    ini_vals3 = modifiedEuler(f,h(i),0,1);

    y_l = linearExplicitLMM(f,h(i),T,ini_vals1,a,B); 
    y_expEu = linearExplicitLMM(f,h(i),T,ini_vals2,a,B); 
    y_modEu = linearExplicitLMM(f,h(i),T,ini_vals3,a,B);
    
    err_l(i) = abs(sqrt(2) - y_l(end));
    err_expEu(i) = abs(sqrt(2) - y_expEu(end));
    err_modEu(i) = abs(sqrt(2) - y_modEu(end));
end

figure(1)
clf
loglog(err_l,'LineWidth',2)
hold on
loglog(err_expEu,'LineWidth',2)
loglog(err_modEu,'LineWidth',2)
xlabel('h')
ylabel('errors')
title('Plot of errors vrs different step sizes')
legend('err-normal','err-expEuler','err-modEuler')

%% Linear Explicit Function
function [y] = linearExplicitLMM(f,h,T,ini_vals,a_j,B_j)
    t = 0:h:T;
    N = length(t);
    m = length(ini_vals);
    y = zeros(1,N);
    y(1:m) = ini_vals;
    for l = 1:N-m
        rhs = B_j * f(t(l:l+m))';
        lhs = a_j * y(l:l+m)';
        y(l+m) = rhs - lhs;
    end
end

function [y] = explicitEuler(f,h,t0,y0)
    y = zeros(1,3);
    y(1) = y0;
    y(2) = y(1)+h*f(t0);
    y(3) = y(2)+h*f(t0+h);
end

function [y] = modifiedEuler(f,h,t0,y0)
    y = zeros(1,3);
    y(1) = y0;
    y(2) = y(1)+h*f(t0+h/2);
    y(3) = y(2)+h*f(t0+h);
end
