function zero = findzero(f, a, b)
    NMAX = 100;     %maximum number of iterations
    fa = f(a);
    % fb = f(b);
    N = 0;      %initialize counter
    while N < NMAX
        m = (a+b)/2;        %bisection of interval
        fm = f(m);
        if (fm == 0 || (b-a)/2 < 1e-4)      %if a zero is found
            zero = m;
            return
        elseif fa * fm < 0 
            b = m;
        else 
            a = m;
            fa = fm;
        end
        N = N+1;        %update counter
    end
    % if NMAX is exceeded, we assume no zero exists
    disp("No solution was found within the interval given")
    zero = nan;
end