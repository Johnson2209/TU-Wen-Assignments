x = load('Data_Assignment09.mat');
x = x.x;
l = @(m,s) sum( log( 1./( pi.*s.*(1+((x-m).^2./s.^2) ) ) ) );  %function to maximize
minimizer=@fminunc;
hx=0.1; % grid in m
hy=0.1; % grid in s
x=3:hx:5;
y=1:hy:3;
nx=length(x);
ny=length(y);
[xx,yy]=meshgrid(x,y);
xx=xx(:);
yy=yy(:);
n = length(xx);
zz = zeros(n,1);
for i = 1:n
    zz(i)=l(xx(i), yy(i));
end
xx=reshape(xx,ny,nx);
yy=reshape(yy,ny,nx);
zz=reshape(zz,ny,nx);
figure(1)
clf
surfl(xx,yy,zz)
colorbar
xlabel('m')
ylabel('s')
zlabel('l')
title('Loglikelihood function')
options=optimset('display','iter','maxiter',1000,'tolfun',1e-8,'tolx',1e-8);
x0=[1.5 2];
[xmin,fval,exitflag,output,allx,hess]=minimizer(@(x) -l(x(1),x(2)),x0,options);

figure(2)
clf
clines = [-fval-16,-fval-9,-fval-4,-fval-1];    %since levels must be monotonic increasin
contour(xx,yy,zz,clines)
hold on
colorbar
p=plot(xmin(1),xmin(2),'m+')
plot(xmin(1),xmin(2),'mo')
xlabel('m')
ylabel('s')
title('Contour plot')
legend(p,'Maximum')
hess_inv = inv(hess)
