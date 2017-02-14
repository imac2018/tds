import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        // Exercice 1

        Book book = new Book("AuthorTest");

        /*
         * Impossible à compiler car les attributs de la classe Book sont privés.
         * On peut changer la visibilité des attributs ou utiliser des accesseurs.
         */

        System.out.println(book.getTitle() + ' ' + book.getAuthor());

        /*
         * Il y a 4 types de visibilités pour les attributs : Privé, protégé, défault et public.
         * Il faut mettre les attributs en privés pour des soucis de sécurité et pour l'ancapsulation.
         * Un accesseur (nécessaire ici) est une méthode d'une classe qui permet à l'extérieur d'avoir un point d'entrée à ses attributs, permettants de modifier et accéder à ceux-ci pour un objet.
         * Si l'on ne souhaite pas que les utilisateurs puissent modifier un attribut, on ne met en place que des getters.
         * Si l'on souhaite indiquer aux développeurs qu'on ne souhaite pas voir un des attributs d'une classe être modifié, on utilise le mot-clé final. Avec ce mot-clé on empêche l'attribut d'être changé
         */

        // Exercice 2

        Book b1 = new Book("Da Java Code", "Duke Brown");
        Book b2 = b1;
        Book b3 = new Book("Da Java Code", "Duke Brown");

        System.out.println(b1 == b2);
        System.out.println(b1 == b3);

        /*
         * Le premier test retourne vrai, le second retourne faux.
         * b2 est bien une référence de b1 mais b3 est un tout autre objet et == ne compare que l'identité d'une référnce.
         */

        System.out.println(b1.equals(b3));

        // La méthode indexOf de java.util.ArrayList : "indexOf(Object o) Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element". (cf: le fucking manual)

        ArrayList list = new ArrayList();
        list.add(b1);

        System.out.println(list.indexOf(b2));
        System.out.println(list.indexOf(b3));

        // Le compilateur affiche 0 mais il est censé afficher -1 car les élements b2 et b3 n'ont pas été ajoutés à la liste. MAIS, comme la méthode equals a été redéfinit juste avant (oui j'ai pris de l'avance), ArrayList croit que b1, b2 et b3 sont le même objet (ce qui n'est pas tout à fait vrai).

        Book aBook = new Book("Da Java Code", "Duke Brown");
        Book anotherBook = new Book(null, null);
        list.add(aBook);
        System.out.println(list.indexOf(anotherBook));

        // L'objet anotherBook a été instancié avec le mot-clé null ce qui lève une NullPointerException
        // Dans l'idéal, il est nécessaire de ne pas utiliser null.
        // java.util.Objects.requireNonNull permet de vérifier qu'un objet n'a pas été instancié à null et renvoie un NullPointerException dans le cas contraire
     }
}
