close()     %close all previous graphs
sym('t');   %create symbolic variable t
a = 0;      
b = 5;
f = @(x) int(t.^(x-1).*exp(-t),t,0,inf)-3;      %explicit function
%call findzero function
result = findzero(f, a, b);  
%Plot function and zero
range = linspace(a,b,100);
plot(range, f(range))   %plot function
grid on     %to create grid co-ordinate system
hold on
plot(result, f(result),'r*')    %plot the found zero of the function
%extras to make the graph nice
title('Graph Of Gamma(x)-3')
xlabel('x')
ylabel('Gamma(x)-3')
legend('Graph of f','Zero of f','Location','northwest')
disp(result);