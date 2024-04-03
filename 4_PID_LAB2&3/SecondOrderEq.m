function G = SecondOrderEq(wn, zeta)
    num = [0, wn^2];
    den = [1, 2*zeta*wn, wn^2];
    G = tf(num, den);
    step(G);
    if abs(zeta) == 0
        state = "unstable" ; poles = "imaginary";
    elseif (0<abs(zeta)) && (abs(zeta)<1)
        state = "underdamped" ; poles = "complex";
    elseif abs(zeta) == 1
        state = "critically damped" ; poles = "real and equal";
    else
        state = "overdamped" ; poles = "real";
    end 
    title(sprintf('Zeta = %.2f; wn = %.2f ; state is %s; poles are %s', zeta,wn,state,poles));
    xlabel('Time')
    ylabel('System Response')
end