clf()

// exo 1

flute = 0

load('~/Documents/c++/tds/signal_s1/td3/flute.dat', 'flute')

N = 5000

// exo 2

x = flute

// CALCUL DE GAMMA_MIN

gammaMin = convol(x, x(length(x) :-1 :1))

// CALCUL DE GAMMA_L ET CL

gammaL1 = [gammaMin(length(x))]

C1 = [gammaMin(length(x) + 1)]

gammaL2 = [ gammaMin(length(x)), gammaMin(length(x) + 1); 
            gammaMin(length(x) + 1), gammaMin(length(x))];
            

C2 = [gammaMin(length(x) + 1); gammaMin(length(x) + 2)]

gammaL3 = [ gammaMin(length(x)), gammaMin(length(x) + 1), gammaMin(length(x) + 2);
            gammaMin(length(x) + 1), gammaMin(length(x)), gammaMin(length(x) + 1);
            gammaMin(length(x) + 2), gammaMin(length(x) + 1), gammaMin(length(x))];

C3 = [gammaMin(length(x) + 1); gammaMin(length(x) + 2); gammaMin(length(x) + 3)]

// CALCUL DE HL

h1 = inv(gammaL1)*C1
h2 = inv(gammaL2)*C2
h3 = inv(gammaL3)*C3

// exo 3

// INIATILISATION

xChapeau1(1) = x(1)

xChapeau2(1) = x(1)
xChapeau2(2) = x(2)

xChapeau3(1) = x(1)
xChapeau3(2) = x(2)
xChapeau3(3) = x(3)

// ITERATIONS

for n = 2:N
    xChapeau1(n) = h1(1)*x(n-1)
end

for n = 3:N
    xChapeau2(n) =  h2(1)*x(n-1) + h2(2)*x(n-2)
end

for n = 4:N
    xChapeau3(n) = h3(1)*x(n-1) + h3(2)*x(n-2) + h3(3)*x(n-3)
end

// CALCUL DES EQM

eqmL1 = 0
for n = 1:N
    eqmL1 = eqmL1 + (x(n) - xChapeau1(n))^2
end
    eqmL1ret = 1/N * eqmL1

eqmL2 = 0
for n = 1:N
    eqmL2 = eqmL2 + (x(n) - xChapeau2(n))^2
end
eqmL2ret = 1/N * eqmL2

eqmL3 = 0
for n = 1:N
    eqmL3 = eqmL3 + (x(n) - xChapeau3(n))^2
end
eqmL3ret = 1/N * eqmL3

// exo 4

//Calcul de dx

sortX = gsort(abs(x),'g','i')
dx = sortX(0.95*N)

// Calcul de dz

zTilde1 = x - xChapeau1
zTilde2 = x - xChapeau2
zTilde3 = x - xChapeau3

absZ1 = abs(zTilde1)
sortZ1 = gsort(absZ1,'g','i')
dz1 = sortZ1(0.95*N)

absZ2 = abs(zTilde2)
sortZ2 = gsort(absZ2,'g','i')
dz2 = sortZ2(0.95*N)

absZ3 = abs(zTilde3)
sortZ3 = gsort(absZ3,'g','i')
dz3 = sortZ3(0.95*N)

// exo 5 - cf papier

// exo 6

function y = quant(x,d,q)
// y = quant(x,d,q) : quantization
// x : input matrix
// d : decision levels
// q : quantization levels

if argn(2) ~= 3 then
   error('Incorrect number of arguments');
end
N = length(q);
if length(d) ~= N+1 then
   error('There must be N+1 decision levels for N quantization levels')
end
[P,Q] = size(x);
x = x(:);
y = zeros(P*Q,1);

d = d(:)';
d = [d(1:N) (1+%eps)*d(N+1)]


for n = 1:N
   ind = find(d(n) <= x & x < d(n+1));
   y(ind) = q(n)*ones(length(ind),1);
end

y = matrix(y,P,Q);

endfunction
   

function y = quantu(x,N,dm)
// y = quantu(x,N,dm) : uniform quantization
// x  : input matrix
// N : number of quantization levels
// dm : vector of minimum and maximum decision levels
//      (default value : dm = [min(x) max(x)])

if argn(2) == 2 then
   dm = [min(x(:)) max(x(:))];
elseif argn(2) ~= 3 then
   error('Incorrect number of arguments');
end
dm(2) = (1+%eps)*dm(2);

d = linspace(dm(1),dm(2),N+1)
q = (d(1:N)+d(2:N+1))/2;

//y = quant(x,d(2:N),q);
y = quant(x,d,q);
endfunction

// CALCUL DE QUANTU AVEC L=3 ET Q=5

dzm = [-dz3,dz3]

signalQuantu = quantu(zTilde3, 5, dzm)

distorsion3 = 0
for i = 1:N
    distorsion3 = distorsion3 +  (x(n) - zTilde3(n))^2
end
distorsion3ret = 1/N * distorsion3




 
