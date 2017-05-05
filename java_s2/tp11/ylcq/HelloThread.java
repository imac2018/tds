public class HelloThread {
    //1. Un Runnable est une interface fonctionnelle qui sert à contenir
    //   un callback à appeler pour le lancement de quelque chose de "Lançable".


    // 2.
    public static void main(String[] args) {
        for(int i=0 ; i<4 ; ++i) {
            int n = i;
            new Thread(() -> {
                for(int j=0 ; j<=5000 ; ++j)
                    System.out.println(n + " " + j);
            }).start();
        }
    }
    // 3. TODO
    // 4. 
}
