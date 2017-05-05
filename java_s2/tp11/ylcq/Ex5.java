import java.util.Scanner;

public class Ex5 {
    // 1. TODO pck c'est pas bien on ne cooupe pas le courant de la console des enfants quand on les appelle à table
    public static void main(String[] args) {
        System.out.println("enter a thread id:");
        try(Scanner scanner = new Scanner(System.in)) {
            while(scanner.hasNextInt()) {
                int threadId = scanner.nextInt();
            }
        }
    }
    // 2. thread.interrupt() sert juste à demander à un thread de s'interrompre.
    //    elle n'est pas statique car il lui faut une cible (ici, 'thread').
    //    Thread.interrupted() indique si le thread actif a reçu une
    //    demande d'interruption.
    //
    // 3. Dans le cadre de la plupart des opérations bloquantes, le thread
    //    reçoit une exception selon le contexte.
    //
    // 4. TODO  Thread.currentThread().interrupt()
    // 5. Thread.interrupted() réinitialise le statut d'interruption du thread actuel, en plus de renvoyer sa valeur précédente.
    //    thread.isInterrupted() renvoie simplement le statut d'interruption sans y toucher.
    //
    //    La métode statique Thread.interrupted() devrait être renommée en quelque chose comme "getInterruptedStatusAndClear()".
    //
    // 6. TODO écrire le code
    // 7. TODO comment faire pour que le programme se termine sur Ctrl+D ?
}
