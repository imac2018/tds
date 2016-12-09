funcprot(0)
clf()

// Ex. 1
function ret=x(t)
    ret = sin(2*%pi*t)
endfunction

L=1000
t=1:0.01:10
subplot(411);
plot(x(t))


// Ex. 2

function ret=Q(x,b)
    q = 2/(2^b)
    ret = q*floor(0.5 + (x-x*q)/q)
endfunction

function y=numerise(x,b)
    y=Q(x(t), b)
endfunction


// Ex. 3

subplot(412); 
plot(numerise(x,16), "y")
plot(numerise(x, 8), "g")
plot(numerise(x, 4), "c")
plot(numerise(x, 2), "b")


// Ex. 4

function ret=EQM(b)
    somme = 0
    y=numerise(x,b)
    for k=t
        somme = somme + (x(k)-y(k))^2
    end
    ret = somme/L
endfunction

subplot(413); 
plot(EQM(16), "y")
plot(EQM( 8), "g")
plot(EQM( 4), "c")
plot(EQM( 2), "b")


// Ex. 5

function ret=RSB(x,y,b)
    sx=0; se=0
    for k=t
        sx = sx + x(k)^2
        se = se + (x(k)-y(k))^2
    end
    ret = 10*log10(sx/se)
endfunction

subplot(414); 
plot(RSB(x(t), numerise(x,16), 16), "y")
plot(RSB(x(t), numerise(x, 8),  8), "g")
plot(RSB(x(t), numerise(x, 4),  4), "c")
plot(RSB(x(t), numerise(x, 2),  2), "b")

