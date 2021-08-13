clear
syms y(t)
syms k M
%% General solution
eq = diff(y)-k*y*(1-y/M);
ysol1 = dsolve(eq);
% nsol=length(ysol1);
% for i=1:nsol
%     s=simplify(subs(eq,y,ysol1(i)))
% end
%% Particular solution
eq_val = subs(eq,{k,M},{0.03,10000});
ypar=simplify(dsolve(eq_val,y(0)==1))
ys = matlabFunction(ypar);
ts = 1:1000;
plot(ts,ys(ts))

%% Carrying capacity
r = 0.95;
ycap = r*ypar*(1-ypar/M)