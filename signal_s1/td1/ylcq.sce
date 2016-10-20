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

subplot(311); 
e=120; Te=1/e; f=(-e):e; plot(tfXe(f), "r");
e=30;  Te=1/e; f=(-e):e; plot(tfXe(f), "m");
e=70;  Te=1/e; f=(-e):e; plot(tfXe(f), "b");

// Ex 4.
subplot(312);
plot(tfx(f), "r");
plot(Te*tfXe(f), "b");

function mask = passebas(f, Te)
    mask = linspace(1,1,length(f));
    mask(find(f < -1/(2*Te))) = 0;
    mask(find(f >  1/(2*Te))) = 0;
endfunction

subplot(313);
plot(tfx(f), "r");
plot(Te*tfXe(f).*passebas(f, Te), "b");
