// Compile with:
//     gcc -Wall -pedantic -Wextra -std=c99 -O3 -march=native td01-pascal2.c

#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#if __GNUC__ && (__x86_64__ || __i386)
#include <x86intrin.h>
#define PASCAL_X86INTRIN 1
#elif _MSC_VER && (_M_IX86 | _M_X64)
#include <intrin.h>
#define PASCAL_X86INTRIN 1
#else
#define PASCAL_X86INTRIN 0
#endif


#if !PASCAL_X86INTRIN

// Implémentation normale, optimisée.
// La 2ème boucle sert à éviter le "tab[n] = 1" qui fait inutilement mal 
// au cache si on sait que pBut > n.
// De manière générale, quand on atteint la colonne pBut du triangle, on n'a
// jamais besoin de calculer ce qui est à droite de celle-ci.
//
// Utiliser des int_fast32_t est (étrangement) 3x plus rapide que uint_fast32_t.
int pascal(int_fast32_t nBut, int_fast32_t pBut){
    int32_t *tab = malloc((nBut+1) * sizeof(int32_t));
    assert(tab); // Pas très correct, mais ça fait le boulot.

    int_fast32_t n;
    tab[0] = 1;
    for(n=1 ; n<=pBut ; ++n) {
        tab[n] = 1;
        for(int_fast32_t i=n-1 ; i>0 ; --i)
            tab[i] += tab[i-1];
    }
    for(    ; n<=nBut ; ++n)
        for(int_fast32_t i=pBut ; i>0 ; --i)
            tab[i] += tab[i-1];

    int result = tab[pBut];
    free(tab);
    return result;
}

#else


#if !__AVX2__

// Cette version fait usage explicite des instructions SSE2 et bat toutes les
// autres à plate couture (et heureusement, sinon on se tire
// une balle).
// Etrangement, même avec toutes les options d'optimisation, mon GCC
// n'en a pas généré de lui-même.
//
// Référence des fonctions _mm* : Intel Intrinsics Guide.

int pascal(int_fast32_t nBut, int_fast32_t pBut){
    int32_t *tab = calloc(nBut+1+4+4, sizeof(int32_t));
    assert(tab); // Pas très correct, mais ça fait le boulot.
    tab += 4;

    int_fast32_t n;
    tab[0] = 1;
    for(n=1 ; n<=pBut ; ++n) {
        tab[n] = 1;
        for(int_fast32_t i=n-1-3 ; i>-4 ; i-=4) {
            __m128i d = _mm_loadu_si128((__m128i*)(tab+i));
            __m128i s = _mm_loadu_si128((__m128i*)(tab+i-1));
            _mm_storeu_si128((__m128i*)(tab+i), _mm_add_epi32(d,s));
        }
    }
    for(    ; n<=nBut ; ++n) {
        for(int_fast32_t i=pBut-3 ; i>-4 ; i-=4) {
            __m128i d = _mm_loadu_si128((__m128i*)(tab+i));
            __m128i s = _mm_loadu_si128((__m128i*)(tab+i-1));
            _mm_storeu_si128((__m128i*)(tab+i), _mm_add_epi32(d,s));
        }
    }

    int result = tab[pBut];
    free(tab-4);
    return result;
}

#else // !__AVX2__

// Encore une autre avec AVX2 ! Supposément 2x plus rapide qu'avec SSE2.
int pascal(int_fast32_t nBut, int_fast32_t pBut){
    int32_t *tab = calloc(nBut+1+8+8, sizeof(int32_t));
    assert(tab); // Pas très correct, mais ça fait le boulot.
    tab += 8;

    int_fast32_t n;
    tab[0] = 1;
    for(n=1 ; n<=pBut ; ++n) {
        tab[n] = 1;
        for(int_fast32_t i=n-1-7 ; i>-8 ; i-=8) {
            __m256i d = _mm256_loadu_si256((__m256i*)(tab+i));
            __m256i s = _mm256_loadu_si256((__m256i*)(tab+i-1));
            _mm256_storeu_si256((__m256i*)(tab+i), _mm256_add_epi32(d,s));
        }
    }
    for(    ; n<=nBut ; ++n) {
        for(int_fast32_t i=pBut-7 ; i>-8 ; i-=8) {
            __m256i d = _mm256_loadu_si256((__m256i*)(tab+i));
            __m256i s = _mm256_loadu_si256((__m256i*)(tab+i-1));
            _mm256_storeu_si256((__m256i*)(tab+i), _mm256_add_epi32(d,s));
        }
    }

    int result = tab[pBut];
    free(tab-4);
    return result;
}
#endif // !__AVX2__

#endif // PASCAL_X86INTRIN

int main() {
    printf(" Cn, p = %d\n", pascal(30000000*2, 250));
    return 0;
}
