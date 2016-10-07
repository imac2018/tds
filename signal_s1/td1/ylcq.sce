funcprot(0)
clf()

f0 = 30

function ret = x(t)
    ret = exp(-sigma)*cos(2*%pi*f0*t)
endfunction

function ret = tfx(f)
    ret = ((sigma*((sigma^2)+4*(%pi^2)*((f-f0).^2)).^(-1)) + (sigma*((sigma^2)+4*(%pi^2)*((f+f0).^2)).^(-1)))/2
endfunction

t = -100:0.1:100
f = t

// Ex 1.
// sigma = 5
// plot(tfx(f), "r")
//sigma = 15
// plot(tfx(f), "b")

// Ex 2.
// Oui, il est théoriquement possible de reconstruire parfaitement x(t) à partir
// de ses échantillons, avec Te assez grand.

// Ex 3.
sigma = 15
Te = %pi
function ret = tfXe(f)
    somme = 0
    for n=-10:10
        somme = somme + tfx(f-n/Te)
    end
    ret = somme/Te
endfunction

subplot(221); e=120; Te=1/e; f=-e/2:e/2; title(string(e)+"Hz"); plot(tfXe(f));
subplot(222); e=70;  Te=1/e; f=-e/2:e/2; title(string(e)+"Hz"); plot(tfXe(f));
subplot(223); e=30;  Te=1/e; f=-e/2:e/2; title(string(e)+"Hz"); plot(tfXe(f));

// Ex 4.

