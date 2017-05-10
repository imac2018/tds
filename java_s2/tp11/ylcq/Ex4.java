import java.util.Scanner;

public class Ex4 {
    // 1.
    // Permettre de tuer un thread sur un coup de tête, c'est permettre au 
    // programme de se retrouver dans un état non cohérent. 
    // Qu'est-ce qui se passe si le thread était en train de faire un
    // calcul critique ? S'il est en pleine communication avec un serveur ?
    // S'il est en train d'écrire dans un fichier important ? S'il avait
    // acquis un verrou ?
    // Pour toutes ces raisons et bien d'autres, tuer un thread n'est 
    // pas permis.
    // 2.
    // thread.interrupt() sert juste à demander à un thread de s'interrompre.
    // elle n'est pas statique car il lui faut une cible (ici, 'thread').
    // Thread.interrupted() indique si le thread actif a reçu une
    // demande d'interruption.
    //
    // 3.
    // Dans le cadre de la plupart des opérations bloquantes, le thread
    //  reçoit une exception selon le contexte.
    //
    // 4.
    // Il ne se passe rien quand on fait Thread.currentThread().interrupt(),
    // à part le fait que Thread.interrupted() et cie renvoient true.
    static void testSelfInterruption() {
        Thread.currentThread().interrupt();
        System.out.println("Is interrupted: " + Thread.interrupted());
    }
    // 5.
    // Thread.interrupted() réinitialise le statut d'interruption du thread 
    // actuel, en plus de renvoyer sa valeur précédente.
    // thread.isInterrupted() renvoie simplement le statut 
    // d'interruption sans y toucher.
    //
    // La métode statique Thread.interrupted() devrait être renommée en quelque
    // chose comme "getInterruptedStatusAndClear()".
    //
    // 6.
    public static void main(String[] args) {

        testSelfInterruption(); // 4.

        final int THREAD_COUNT = 4;
        Thread[] threads = new Thread[THREAD_COUNT];
        for(int i=0 ; i<THREAD_COUNT ; ++i) {
            int thread_index = i;
            threads[i] = new Thread(() -> {
                for(int c=0 ; !Thread.interrupted() ; c++) {
                    System.out.println(thread_index + " " + c);
                    try {
                        Thread.sleep(1000);
                    } catch(InterruptedException e) {
                        break;
                    }
                }
            });
            threads[i].start();
        }

        System.out.println("enter a thread id:");
        try(Scanner scanner = new Scanner(System.in)) {
            while(scanner.hasNextInt()) {
                int i = scanner.nextInt();
                threads[i].interrupt();
            }
            scanner.close();
            System.out.println("Finished!");
        }
    }
    // 7.
    // J'ai essayé du mieux que je pouvais d'après les réponses existantes
    // sur StackOverflow mais aucune ne marche chez moi.
    // Ca impliquait l'utilisation de scanner.hasNextLine()
    // (puis Integer.parseInt()) mais rien n'y fait.
}
