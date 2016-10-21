funcprot(0)
clf()

// Ex.1
cd("/home/6im2/ylecoq/prog/tds/signal_s1/td3");
load("flute.dat");

x=flute;
N=length(x);
disp("N = " + string(N));
// plot(x)

// Ex.2
function ret = petit_gamma(x)
    ret = convol(x,x(length(x):-1:1));
endfunction

function ret = GAMMA_L(x, L)
    gamma_x = petit_gamma(x);
    for i=1:L
        for j=1:L
            ret(i,j) = gamma_x(abs(i-j)+length(x));
        end
    end
endfunction

for L=1:3
    disp("L = " + string(L));
    
    petit_gamma_x = petit_gamma(x);
    cL = petit_gamma_x((length(x)+1):(length(x)+L));
    disp("cL = ");
    disp(string(cL));

    GAMMA_L_x = GAMMA_L(x, L);
    disp("GAMMA_L = ");
    disp(string(GAMMA_L_x));

    hL = inv(GAMMA_L_x)*cL';
    disp("hL = ");
    disp(string(hL));
end

// Ex.3
function ret = EQM(x, L)
    N = length(x);
    somme = 0;
    for n=1:N
        somme = somme + (x(n)-x_chapeau(n))^2;
    end
    ret = somme/N;
endfunction
