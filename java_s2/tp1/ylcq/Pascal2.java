public class Pascal2 {
    public static int pascal(int nBut, int pBut) {
        int[] tab = new int[nBut+1];
        tab[0] = 1;
        
        int n;
        /* La programme est plus rapide avec cette boucle là
         * que les deux boucles commentées plus bas. */
        for(n=1 ; n<=nBut ; ++n) {
            tab[n] = 1;
            for(int i=(pBut<n-1 ? pBut : n-1) ; i>0 ; --i)
                tab[i] += tab[i-1];
        }
        /*
        for(n=1 ; n<=pBut ; ++n) {
            tab[n] = 1;
            for(int i=n-1 ; i>0 ; --i)
                tab[i] += tab[i-1];
        }
        for(    ; n<=nBut ; ++n) 
            for(int i=pBut ; i>0 ; --i)
                tab[i] += tab[i-1];
        */

        return tab[pBut];
    }
    public static void main(String[] args) {
        System.out.println("Cn, p = " + pascal(30000000*2, 250));
    }
}
