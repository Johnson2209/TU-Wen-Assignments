holdstatus=ishold;
if ~ishold,hold on;end
xl=xlim;
yl=ylim;
plot(xl,[0 0],'k:')
plot([0 0],yl,'k:')
if ~holdstatus,hold off;end
