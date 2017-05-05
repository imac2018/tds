public class HelloThreadJoin {
    public static void main(String[] args) {
        final int THREAD_COUNT = 4;
        Thread[] threads = new Thread[THREAD_COUNT];
        for(int i=0 ; i<THREAD_COUNT ; ++i) {
            int n = i;
            threads[i] = new Thread(() -> {
                for(int j=0 ; j<=5000 ; ++j)
                    System.out.println(n + " " + j);
            });
            threads[i].start();
        }
        for(int i=0 ; i<THREAD_COUNT ; ++i) {
            try {
                threads[i].join();
            } catch(InterruptedException e) {
            }
        }
    }
}
