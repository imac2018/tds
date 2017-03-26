package fr.umlv.morse;

public class Morse {
    public static void main(String[] args) {
    
        /* for(String arg : args)
         *  System.out.println(arg + " Stop. ");
         */

        // 2.
        // - A construire des String, duh !
        // - Sûrement pour chaîner des méthodes sur ce même objet.
        //   La doc dit que append() renvoie l'objet lui-même.
        //
        

        // Pour le coup, je ne vois pas vraiment l'avantage d'utiliser un StringBuilder
        // à part le fait qu'on ait à dispositions des méthodes toutes jolies pour faire des
        // trucs.
        StringBuilder newString = new StringBuilder();

        for(String item : args)
            newString.append(item).append(" Stop. ");
        
        System.out.println(newString);
    }
}
