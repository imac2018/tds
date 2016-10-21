clf()

// exo1

function signal=TF(f, nbre)
    freq=30
    signal=(1/2)*((nbre*(nbre^2+4*%pi^2*(f-freq).^2).^(-1))+(nbre*(nbre^2+4*%pi^2*(f+freq).^2).^(-1)));
endfunction

function x=X(t,nbre)
    freq=30
    x=exp(-nbre*(abs(t))).*cos(2*%pi*freq*t)
endfunction

signal1 = [-100:1:100]
signal2 = [10:1:100]

a =  TF(signal1, 15)
w = find(a<35)



//subplot(511)
//plot(signal1, TF(signal1, 5),'r')
//plot(signal1, TF(signal1, 15),'b')

//subplot(512)
//plot(signal2,X(signal2,5),'r')
//plot(signal2,X(signal2,500),'b')

// Lorsque 'nbre' augmente, l'amplitude du signal diminue

// exo2

// Il est théoriquement possible de reconstruire un signal échantillonné avec une valeur Fe très élevé.

// exo3

function x=TFe(f,fe,nbre)
    x = 0
    for i = -10:10
        x = x + TF(f - (i*fe), nbre)
    end
    x = fe * x 
endfunction

function x=TeTFe(f,fe,nbre)
    x = 0
    for i = -10:10
        x = x + TF(f - (i*fe), nbre)
    end 
endfunction

function x=TFepassebas(f,fe)
    x = linspace(1,1,length(f));
    x(find(f >  (0.5*fe))) = 0;
    x(find(f <  -(0.5*fe))) = 0;
endfunction

fe1 = 120
fe2 = 70
fe3 = 30

bandefe1 = [-(fe1/2):fe1/2]
bandefe2 = [-fe2:fe2]
bandefe3 = [-(fe3/2):fe3/2]

//subplot(513)
//plot(bandefe1, TFe(bandefe1, fe1, 15))
//subplot(514)
//plot(bandefe2, TFe(bandefe2, fe2, 15))
//subplot(515)
//plot(bandefe3, TFe(bandefe3, fe3, 15))

// exo4


subplot(511)
plot(bandefe2, TeTFe(bandefe2, fe2, 15))
plot(signal1, TF(signal1, 15),'r')
subplot(512)
plot(bandefe2, TeTFe(bandefe2, fe2, 15) * (1/70) .* TFepassebas(bandefe2, fe2))



