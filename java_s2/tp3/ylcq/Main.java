import java.util.ArrayList;

public class Main {
    // ex1.3
    // Les champs sont privés. Il faut soit les mettre public, soit faire
    // des getters.
    public static void main(String[] args) {
        // Book book = new Book("Foo", "Foobar"); // 7.
        // System.out.println(book.title + ' ' + book.author);
       
        // ex2.1
        // Book b1 = new Book("Da Java Code", "Duke Brown");
        // Book b2 = b1;
        // Book b3 = new Book("Da Java Code", "Duke Brown");
        // System.out.println(b1 == b2);
        // System.out.println(b1 == b3);
        // Ca affiche true false parce '==' teste l'égalité de valeurs, et
        // la "valeur" d'un objet est sa référence.
        // C'est donc une égalité de référence et non du contenu.
        //
        // ex2.4
        // Book b1 = new Book("Da Java Code", "Duke Brown");
        // Book b2 = b1;
        // Book b3 = new Book("Da Java Code", "Duke Brown");

        // ArrayList list = new ArrayList();
        // list.add(b1);
        // System.out.println(list.indexOf(b2));
        // System.out.println(list.indexOf(b3));
        // Ca affiche 0 0 !
        //
        // ex2.5
        // Ca appelle la méthode equals() si l'objet cherché est non null.
        //
        // ex2.9
        // Book aBook = new Book("Da Java Code", "Duke Brown");
        // Book anotherBook = new Book(null, null);
        // ArrayList list = new ArrayList();
        // list.add(aBook);
        // System.out.println(list.indexOf(anotherBook));
        //
        // Ca fait une NullPointerException dans Book.equals() !
        // Un code doit planter s'il est mal utilisé parce que si on 
        // le laisse tourner dans la nature, des effets indésirables 
        // se produiront sans qu'on sache pourquoi !
        // Il faut empêcher carrément la création de livres aux 
        // attributs null, donc modifier le code du constructeur.
        //
        // ex2.10
        // Il ne faut se permettre d'avoir null comme référence possible si
        // et seulement si ça "apporte quelque chose", dans le sens 
        // "représentation d'un objet inexistant ou invalide".
        // Pour tous les autres cas, il faut empêcher au maximum son apparition.
        //
        // ex3.1
        Book book = new Book("Da Java Code", "Dan Duke");
        System.out.println(book);
        Book book1 = new Book("Da Java Code");
        System.out.println(book1);
        Book book2 = new Book("Da Java Code", "<no author>");
        System.out.println(book2);
    }
    // ex1.4
    // public - protected - default - private.
    // Il n'y a pas de peine de mort, les différentes visibilités existent
    // pour une raison. Cela dit, on peut vouloir préférer mettre les attributs
    // en private pour mieux contrôler les accès.
    //
    // ex1.5
    // Un accesseur est une fonction dédiée à l'obtention ou modification des 
    // attributs.
    // Bah, on devrait les mettre en private, mais je ne vois pas le problème
    // qu'il y aurait avec public. Ca ne sert à rien de cacher jalousement ce
    // qu'on manipule - au contraire, ces données sont importantes.
    //
    // ex1.6
    // Utiliser le mot-clé final (si c'est un type primitif ou non-mutable).
    // Sinon, le déclarer comme occurence de classe non-mutable.
    // C'est important pour forcer nos intentions à la compilation, au lieu
    // d'avoir des mauvaises surprises à l'exécution.
}
