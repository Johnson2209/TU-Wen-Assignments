opt=odeset('maxstep',0.01);
%
syms y(t)
syms a q
eq = diff(y,2)+[a-2*q*cos(2*t)]*y
eq1 = subs(eq,{a,q},{1.5,0.5})
eqsys = odeToVectorField(eq1)
f = matlabFunction(eqsys,'vars',{'t','Y'})
% Time interval
tspan=[0 100];
% Initial conditions
y0 = [1;1]
% solve the system
[t,y]=ode23(f,tspan,y0,opt);



%% undamped pendulum of length l

figure(1)
clf
hold on
plot(t,y(:,1),'b')
plot(t,y(:,2),'b:')
box on
draw_axes
xlabel('t')
ylabel('y(t) & y''(t)')
%legend('')
