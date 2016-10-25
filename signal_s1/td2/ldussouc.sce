
clf()

// ex 1

taille = [0:0.001:10]
tailleY = [0:0.001:10]
function x=signal(t)
    x = sin(2*%pi*t)
endfunction

// ex 2

subplot(411)
plot(taille, signal(taille))

function y=numerise(x, bits)
    q = 2/(2^bits)
    y = q * floor( (((x*(1-q))/q)+0.5) )
endfunction

// ex 3

subplot(412)
plot(taille, numerise(signal(taille),2),'r')
plot(taille, numerise(signal(taille),4),'g')
plot(taille, numerise(signal(taille),8),'m')

subplot(413)
plot(taille, numerise(signal(taille),8),'m')
plot(taille, numerise(signal(taille),16), 'b')

// ex 4

function sig=eqm(signaldepart, signalquantifie)
   ret = 0 
   for i = 1:1000
       ret = ret * (signaldepart(i) - signalquantifie(i))^2    
   end
   sig= ret / 1000
endfunction

disp(eqm(signal(taille),numerise(signal(taille), 2)), 'r')

//ex 5

function ret=RSB(vec1,vec2)
    calcVec1=0; calcVec2=0
    for i = t
        calcVec1 = calcVec1 + vec1(i)^2
        calcVec2 = calcVec2 + (vec1(i)-vec2(i))^2
    end
    ret = 10*log10(calcVec1/ calcVec2)
endfunction

subplot(414)
// A compléter
//plot(RSB(x(taille),4)
