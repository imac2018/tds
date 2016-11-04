funcprot(0);
clf();

// Ex. 1
N=64;
function y=xn(f0)
    NN = N; 
    D = 1:NN; 
    bn = rand(1,NN,"normal");
    y(D) = cos(2*%pi*f0*D) + bn;
endfunction

x=xn(1/16);
tfx=fft(x);
//subplot(221);
//title("x");
//plot(x);
//subplot(222);
//title("TF(x)");
//plot(tfx); //Symétrie horizontale triviale !
//subplot(223);
//title("Module de TF(x)");
//plot(abs(tfx)); //Symétrie horizontale !
//subplot(224);
//title("Phase de TF(x)");
//plot(atan(imag(tfx),real(tfx))); //Symétrie hermitienne !


// Ex. 2
Ex=sum(abs(x).^2);
disp("Energie de x     = " + string(Ex));
Etfx=sum(abs(tfx).^2)/N;
disp("Energie de TF(x) = " + string(Etfx));
//Théorème de Parseval !


// Ex. 3
y = rand(1,N,"normal");
z = convol(x,y);


// Ex. 4
tfy=fft(y);
zprime=ifft(tfx.*tfy);
//zprime=ifft(tfx'*tfy); // #ArtAbstrait
//subplot(211);
//plot(z, "b");
//subplot(212);
//plot(zprime, "r");
// zprime ressemble de plus en plus à z quand on regarde à droite.


// Ex. 5
I=(N+1):(N+1+N);
x(I) = 0;
y(I) = 0;
tfx=fft(x);
tfy=fft(y);
//z = convol(x,y);
zprime=ifft(tfx.*tfy);
//subplot(211);
plot(z, "b");
//subplot(212);
plot(zprime, "r");

