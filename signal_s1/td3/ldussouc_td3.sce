clf()

// exo 1

flute = 0

load('~/Documents/c++/tds/signal_s1/td3/flute.dat', 'flute')

disp(length(flute))

N = 5000

// exo 2

x = flute

hL = [0,0,0]

gammaMin = convol(x, x(length(x) :-1 :1))

gammaL1 = [gammaMin(length(x))]

C1 = [gammaMin(length(x) + 1)]

gammaL2 = [ gammaMin(length(x)), gammaMin(length(x) + 1); 
            gammaMin(length(x) + 1), gammaMin(length(x))];
            

C2 = [gammaMin(length(x) + 1); gammaMin(length(x) + 2)]

gammaL3 = [ gammaMin(length(x)), gammaMin(length(x) + 1), gammaMin(length(x) + 2);
            gammaMin(length(x) + 1), gammaMin(length(x)), gammaMin(length(x) + 1);
            gammaMin(length(x) + 2), gammaMin(length(x) + 1), gammaMin(length(x))];

C3 = [gammaMin(length(x) + 1); gammaMin(length(x) + 2); gammaMin(length(x) + 3)]

h1 = inv(gammaL1)*C1
h2 = inv(gammaL1)*C2
h3 = inv(gammaL1)*C3

disp(h1(1))
disp(h2(1), h2(2))
disp(h3(1), h3(2), h3(3))

// exo 3

xChapeau = 
