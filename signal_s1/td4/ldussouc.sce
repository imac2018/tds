funcprot(0)
clf()

// exo 1

function ret= sig(nbre, fzero)
    bn = rand(nbre,'normal')
    ret = cos(2*%pi*fzero*nbre)+ bn
endfunction


fzero = 1/16
echantillon = [1:64]
x_n = sig(echantillon, fzero)
fftsignal = fft(x_n,-1)

subplot(421)
plot(fftsignal,'b')
xtitle('fft du signal', 'X axis', 'Y axis', 'Z axis', boxed = 1 );

modulefft = abs(fftsignal)
phasefft = atan(imag(fftsignal),real(fftsignal))

subplot(422)
plot(modulefft,'r')
xtitle('module de fft du signal', 'X axis', 'Y axis', 'Z axis', boxed = 1 );

subplot(423)
plot(phasefft,'m')
xtitle('phase de fft du signal', 'X axis', 'Y axis', 'Z axis', boxed = 1 );

// On trouve une symétrie sur l'axe des Y à la moitié de l'échantillon pour 
// le module et une symétrie sur l'axe des X et Y sur la phase.

// exo 2

sumSignal = sum(x_n.^2)
sumfft = sum((abs(fftsignal.^2))) / 64

// L'énergie du signal est la même que sa fft, Parseval disait vrai !

// exo 3

y_n = rand(echantillon, 'normal')
z_n = convol(x_n, y_n)

subplot(424)
plot(z_n,'b')
plot(zprim_n,'m')
xtitle('z_n', 'X axis', 'Y axis', 'Z axis', boxed = 1 );

// exo 4

y_nfft = fft(y_n,-1)
mult_signals = y_nfft .* fftsignal
zprim_n = ifft(mult_signals)

subplot(425)
plot(zprim_n,'m')
xtitle('fft de z_n', 'X axis', 'Y axis', 'Z axis', boxed = 1 );

// la tfd z'n est la moitié du signal zn

// exo 5 

new_x_nfft = fft([x_n, zeros(1,64)])
new_y_nfft = fft([y_n, zeros(1,64)])

mult_new_signals = new_x_nfft .* new_y_nfft

new_z_n = ifft(mult_new_signals)

subplot(426)
plot(new_z_n,'m')
xtitle('fft de x_n + 64 zéros', 'X axis', 'Y axis', 'Z axis', boxed = 1 );

// exo 6

// circulaire vs linéaire et comment ça s'applique dans le sujets
