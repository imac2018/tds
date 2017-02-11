public class Ex1 {
    public static void main(String[] args) {
        // 1.
        // On a true puis false, parce que l'opérateur '==' teste l'égalité
        // des références, et non du contenu (C'est donc similaire à comparer 
        // deux pointeurs).
        String s1 = "toto";
        String s2 = s1;
        String s3 = new String(s1);

        System.out.println(s1 == s2); // true
        System.out.println(s1 == s3); // false

        // 2.
        // C'est equals().
        String s4 = "toto";
        String s5 = new String(s4);

        System.out.println(s4.equals(s5)); // true

        // 3.
        // On a true parce que "toto" est stockée dans une section spéciale, et
        // puisque les String sont immutables, notre code ne peut pas écrire
        // dans cette section. Ainsi, le compilateur a décidé de ne stocker
        // "toto" qu'une fois et donner son adresse à la fois à s6 et s7.
        String s6 = "toto";
        String s7 = "toto";

        System.out.println(s6 == s7); // true
     
        // 4.
        // Je ne sais pas, c'est bizarre ! Rien ne les as obligés à faire que
        // les Strings soient liées aux constantes de chaînes de caractère
        // stockées dans une section en lecture seule.
        // Une chaîne de caractère est, quoiqu'on dise, un tableau de données -
        // je ne vois pas pourquoi leur traitement devrait être différent 
        // d'un tableau normal. Quand on veut une chaîne immutable
        // en C++, on met juste const - sinon c'est mutable et personne ne 
        // s'en plaint.
        // Je suppose que la réponse est "parce qu'ils ont cru que c'était
        // une bonne idée". Je ne crois pas en l'argument "sécurité" rabaché
        // sur la même question sur Stack Overflow. ^^
        //
        // 5.
        // Ca affiche juste "hello" parce que toUpperCase() ne convertit pas
        // la String - elle en renvoie une à la place.
        String s8 = "hello";
        s8.toUpperCase();
        System.out.println(s8); // hello
    }
}
