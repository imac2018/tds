import java.util.ArrayList;
import java.util.Collections;

public class HelloListBug {
    public static void main(String[] args) {

        final int THREAD_COUNT = 4;
        Thread[] threads = new Thread[THREAD_COUNT];
        //ArrayList<Integer> results = new ArrayList<Integer>(THREAD_COUNT*5000);
        ArrayList<Integer> results = new ArrayList<Integer>();

        for(int i=0 ; i<THREAD_COUNT ; ++i) {
            int n = i;
            threads[i] = new Thread(() -> {
                for(int j=0 ; j<=5000 ; ++j) {
                    synchronized(results) { // 4.
                        results.add(j);
                    } // 4.
                }
            });
            threads[i].start();
        }
        for(int i=0 ; i<THREAD_COUNT ; ++i) {
            try {
                threads[i].join();
            } catch(InterruptedException e) {
                System.err.println(e);
            }
        }
        System.out.println(""+ results.size());
    }
    // 1.
    // Whoops ! On a trois IndexOutOfBoundsExceptions, dans un ordre aléatoire
    // à chaque run.
    //
    // 2.
    // ArrayList.add() incrémente un int modCount, qui sert d'index dans le 
    // tableau pour le placement de la prochaine valeur, mais l'opération
    // n'est pas atomique.
    // La méthode s'asure bien que l'ArrayList a une capacité suffisante, mais
    // ce n'est pas lié au problème.
    //
    // 3.
    // J'obtiens 19550, 19468, 19187, et autres valeurs aléatoires de ce 
    // genre à chaque run.
    // C'est lié au fait que chaque thread doit load l'index dans un
    // de ses registres, faire une opération avec, puis faire un store
    // dans la mémoire. Sans synchronisation, un thread est tout à fait capable
    // d'écraser une valeur précédemment store-ée dans la mémoire avec sa
    // valeur à lui.
    //
    // 4.
    // cf. l'ajout de synchronized(results).
    // Ca marche, j'obtiens 20004 de manière consistente (de 0 à 5000 inclus,
    // ça fait 5001 valeurs en tout, fois 4).
}
