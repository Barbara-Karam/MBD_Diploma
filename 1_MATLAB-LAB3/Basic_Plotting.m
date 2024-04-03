x= linspace(-2*pi,2*pi,100);
y1=sin(x);
y2=cos(x);
plot(x,y1,'Color','red','line','dashed','marker','square');
xlabel('X-Axix');
xlabel('Y-Axix');
legend('sin x','cos x')