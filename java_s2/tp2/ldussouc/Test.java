public class Test {
    public static void main(String[] args) {

        // Avec la compilation javap on comprend que l'opérateur + sur un string
        // c'est un peu la même chose que de faire un StringBuilder avec .append()
        for(String arg : args)
             System.out.println(arg + " Stop. ");
    }
}
