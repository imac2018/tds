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

    hL_ = inv(GAMMA_L_x)*cL';
    disp("hL = ");
    disp(string(hL_));
end

// Ex.3
function ret = hL(L)
    // Repris du code précédent
    petit_gamma_x = petit_gamma(x);
    cL            = petit_gamma_x((length(x)+1):(length(x)+L));
    GAMMA_L_x     = GAMMA_L(x, L);
    ret           = inv(GAMMA_L_x)*cL';
endfunction

function ret = x_chapeau_n(n,L,hL_)
    ret = 0;
    for i=1:L
        ret = ret + hL_(i)*x(n-i);
    end
endfunction

function ret = x_chapeau(L)
    N = length(x);
    hL_ = hL(L);
    ret(1:L) = x(1:L);
    for n=(L+1):N
        ret(n) = x_chapeau_n(n,L,hL_); 
    end
endfunction

function ret = EQM(x, L)
    N = length(x);
    somme = 0;
    xchapeau = x_chapeau(L);
    for n=1:N
        somme = somme + (x(n)-xchapeau(n))^2;
    end
    ret = somme/N;
endfunction

for L=1:3
    disp("EQM avec L=" + string(L) + " : " + string(EQM(x,L)));
end
// L décrôit proportionnellement à L.

// Ex. 4

//L'énoncé reformulé :
//dx vérifie dx > abs(95% des échantillons).
x_trie = gsort(abs(x)); //décroissant
dx = x_trie((1-0.095)*N);
z = x-x_chapeau(1);
//plot(z);
z_trie = gsort(abs(z)); //décroissant
dz = z_trie((1-0.095)*N);
disp("dx : " + string(dx));
disp("dz : " + string(dz));

// Ex. 5
//....


//Ex. 6
getd(".")
L=3;
Q=5;
xchap = x_chapeau(L);
z_tilde = x-xchap;
z_barre = quantu(z_tilde, Q, [-dz;dz]);
compresse = xchap + z_barre;
