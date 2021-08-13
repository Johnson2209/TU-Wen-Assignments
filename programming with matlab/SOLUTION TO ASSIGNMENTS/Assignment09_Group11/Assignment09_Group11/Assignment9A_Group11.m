minimizer=@fmincon; % function handle
myfun1=@(x,y) x(:,1).*y(:,1); % minimize f(x,y) = x*y
myfun2=@(x,y) -x(:,1).*y(:,1); % maximize f(x,y) = x*y
hx=0.05; % grid in x
hy=0.05; % grid in y
x=-2:hx:2;
y=-2:hy:2;
nx=length(x);
ny=length(y);
[xx,yy]=meshgrid(x,y);
xx=xx(:);
yy=yy(:);
zz1=myfun1(xx,yy);
zz2=myfun2(xx,yy);
xx=reshape(xx,ny,nx);
yy=reshape(yy,ny,nx);
zz1=reshape(zz1,ny,nx);
zz2=reshape(zz2,ny,nx);
figure(1)
clf
surfl(xx,yy,zz1)
colorbar
xlabel('x')
ylabel('y')
zlabel('z')
title('Plot of f(x,y)=xy')
figure(2)
clf
surfl(xx,yy,zz2)
colorbar
title('Plot of f(x,y)=-xy')
xlabel('x')
ylabel('y')
zlabel('z')
figure(3)
clf
contour(xx,yy,zz1,100)
hold on
colorbar
title('Contour plot of f(x,y)=xy')
xlabel('x')
ylabel('y')
axis equal
options=optimset('display','final','maxiter',1000,'tolfun',1e-8,'tolx',1e-8);
%% nonlinear equality: x^2+y^4 = 1
x0=[1 1];
% y0=[1 1];
[xmin,fval1,exitflag1]=minimizer(@(x) myfun1(x(1),x(2)),x0,[],[],[],[],[],[],@(x) nlcon(x));
[xmax,fval2,exitflag2]=minimizer(@(x) myfun2(x(1),x(2)),x0,[],[],[],[],[],[],@(x) nlcon(x));
p1 = plot(xmin(1),xmin(2),'m+');
plot(xmin(1),xmin(2),'mo')
p2 = plot(xmax(1),xmax(2),'kx');
plot(xmax(1),xmax(2),'ko')
p3 = fimplicit(@(x,y)x.^2+y.^4 - 1,'r');
legend([p1 p2 p3],{'Min','Max','Constraint'})
legend('boxoff')
xlim([-2 2])
ylim([-2 2])
%%
function [C,Ceq]=nlcon(x)
C=[];
Ceq = x(1).^2 + x(2).^4 - 1;
end
