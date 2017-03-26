public class Ex1 {
    
    public static void main(String[] args) {
       
        String s1 = "toto";
        String s2 = s1;
        String s3 = new String(s1);
        
        // Le deuxième est test est faux car == ne teste que l'égalité des références
        // entre deux objets
        System.out.println(s1 == s2);
        System.out.println(s1 == s3); 


        String s4 = "toto";
        String s5 = new String(s4);

        System.out.println(s4.equals(s5));


        // Les deux variables sont de types String, ainsi leurs valeurs 
        // correspondent à un seul et unique contenu qui a deux addresse : s6 et s7

        // String est immutable pour des raisons de sécurité, de synchronisation
        // et d'optimisations mais c'est surtout ce qu'on trouve sur internet
        String s6 = "toto";
        String s7 = "toto";

        System.out.println(s6 == s7);
     

        // On affiche "hello" en minuscule parce que toUpperCase() est une méthode
        // qui crée un nouvelle objet que l'on doit créer mais ne peut modifier un String. 
        String s8 = "hello";
        s8.toUpperCase();
        System.out.println(s8);
    }
}
