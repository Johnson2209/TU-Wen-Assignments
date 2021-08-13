%% Definitions and Initializations
a0 = -5;
a1 = 4;
B0 = 2;
B1 = 4;
f = @(t,y) -y;
y0 = 1;
t0 = 0;  T = 1;
step_sizes = 2.^-(1:50);
errors = [];
%% Varying step sizes and Plotting
for h = step_sizes
  tspan = t0:h:T;
  y1 = exp(-h);
  [y,err] = solve(f,y0,y1,tspan,h,a0,a1,B0,B1);
  errors(end+1) = err;
end
clf
figure(1)
loglog(step_sizes,errors);
xlabel('h')
ylabel('Error')

%% Actual two step method
function [y,err] = solve(f,y0,y1,t,h,a0,a1,B0,B1)
  % f- function handle
  N = length(t);
  y = zeros(1,N);
  y(1) = y0;
  y(2) = y1;
  for l = 1:N-2  
    y(l+2) = -a1*y(l+1) - a0*y(l) + h*(B1*f(t(l+1),y(l+1)) + B0*f(t(l),y(l)));
  end
  err = abs(exp(-1)-y(N));
end