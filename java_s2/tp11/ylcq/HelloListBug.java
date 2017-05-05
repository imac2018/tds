import java.util.ArrayList;
import java.util.Collections;

public class HelloListBug {
    public static void main(String[] args) {

        final int THREAD_COUNT = 4;
        Thread[] threads = new Thread[THREAD_COUNT];
        ArrayList<Integer> results = new ArrayList<Integer>(THREAD_COUNT*5000);

        for(int i=0 ; i<THREAD_COUNT ; ++i) {
            int n = i;
            threads[i] = new Thread(() -> {
                for(int j=0 ; j<=5000 ; ++j) {
                    synchronized(results) {
                        results.add(j);
                    }
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
    // 1. TODO noter les différents affichages
    // 2. TODO inspecter la source de ArrayList.add()
    // OK, ça incrémente un modCount, ce qui n'est pas
    // atomique (c'est l'index où l'élément est écrit)
    // 3. TODO
    // 4. TODO
}
