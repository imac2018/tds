import java.util.Objects;

// ex1.1
public class Book {
    private final String title, author;
    private final static String NO_AUTHOR = "<no author>";
    // ex1.2
    // On obtient "null null" car les attributs sont initialisés si on ne
    // le précise pas.
    // public static void main(String[] args) {
    //     Book book = new Book();
    //     System.out.println(book.title + ' ' + book.author);
    // }

    // ex1.7
    // Haha, title et title c'est le même identificateur, comment c'est
    // qu'on fait pour les différencier ?? :)
    //
    // ex2.11
    public Book(String title, String author) {
        this.title  = Objects.requireNonNull(title);
        this.author = Objects.requireNonNull(author);
    }
    public Book(String title) {
        this(title, new String(NO_AUTHOR));
    }
    public Book() {
        this("<untitled>");
    }
    // ex1.10
    // Le compilateur est trop fort.
    //
    // ex1.11
    // Voir au-dessus.
    
    // ex2.2
    // ex2.6
    // ex2.7
    // ex2.8
    // Override sert à générer une erreur de compilation si le nom de la méthode
    // ne correspond pas à une méthode de la sous-classe.
    @Override
    public boolean equals(Object o) {
        if(o==null || !(o instanceof Book))
            return false;
        Book b = (Book)o;
        return title.equals(b.title) && author.equals(b.author);
    }
    // ex2.3
    // La méthode indexOf() de ArrayList sert à chercher un objet d'après
    // son contenu et renvoyer son index dans le tableau.
    //
    // ex3.1
    // ex3.2 Oui, carrément.
    // ex3.3
    @Override
    public String toString() {
        return title + (hasAuthor() ? " by " + author : "");
    }
    private boolean hasAuthor() {
        return author.equals(NO_AUTHOR) ? author==NO_AUTHOR : true;
    }
}
