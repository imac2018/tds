public class Test {
    public static void main(String[] args) {
        // String first  = args[0];
        // String second = args[1];
        // String last   = args[2];
        // System.out.println(first + ' ' + second + ' ' + last);
        // 
        // 4.
        // On peut utiliser ' ' parce que c'est le caractère espace, et non
        // la chaîne de caractères consistant en un seul espace.
        //
        // OMG ! Avec 'javap -c', on voit que les opérateurs '+' sont compilés
        // directement comme des appels à StringBuilder.append() !
        //
        //
        // 5.
        for(String arg : args)
             System.out.println(arg + " Stop. ");
        // Ca fait encore des appels à StringBuilder.append().
        // Je ne sais pas quoi en déduire.
        // Je ne sais pas non plus quand utiliser append() vs '+'. Le dernier
        // a l'air d'être défini comme étant le 1er de toute façon.
        //
        // (question des gros yeux) :
        // - C'est pas consistent, si on fait un append(), autant faire le reste
        //   de la sorte.
        // - C'est une "code smell";
        // - Je vois pas sinon.
    }
}
