package fr.umlv.morse;

public class Morse {
    public static void main(String[] args) {
        // 1.
        // for(String arg : args)
        //     System.out.println(arg + " Stop. ");

        // 2.
        // - A construire des String, duh !
        // - Sûrement pour chaîner des méthodes sur ce même objet.
        //   La doc dit que append() renvoie l'objet lui-même.
        //
        // 3.
        // L'avantage c'est qu'on ne fait println qu'une seule fois, mais...
        // Ca n'aurait pas pu être aussi fait avec la concaténation normale
        // de String ? ._.
        StringBuilder sb = new StringBuilder();
        for(String arg : args)
            sb.append(arg).append(" Stop. ");
        System.out.println(sb);
    }
}
