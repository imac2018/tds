import java.util.Optional;
import java.util.Objects;

public class ArrayShoppingCart {
    // 1. Non !
    private Book[] books;
    private int book_count;
    // L'idée ici, ça va être d'allouer un tableau de taille fixe d'un seul
    // coup, où seules les cases de 0 à book_count sont utilisées, et le
    // reste inutilisées.
    // Il n'y a pas de "trous" (nulls) entre 0 et book_count.
    // Le contenu des autres cases doit être traité comme indéterminé.
    // Il n'y a pas d'ordre de tri.

    // 2.
    public ArrayShoppingCart(int max) {
        books = new Book[max];
        book_count = 0; // Je le mets explicitement, mais ça aurait été
        // initialisé à zéro par défaut puisque c'est un attribut.
    }
    // Dans le main(), le test cause une ArrayIndexOutOfBoundsException.
    // Il faut que add() lance une exception appropriée, plus explicatrice.
    public void add(Book b) {
        if(book_count >= books.length)
            throw new IllegalStateException("Limite dépassée, impossible de faire l'ajout");
        books[book_count++] = b;
    }
    // 3.
    public int numberOfBooks() { return book_count; }

    // 4.
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Nombre de livres: ").append(numberOfBooks()).append("\n");
        for(int i=0 ; i<numberOfBooks() ; ++i)
            sb.append(books[i]).append("\n");
        return sb.toString();
    }
    public void displayContents() {
        System.out.println(this);
    }

    // 5.
    public Optional<Book> longestTitle() {
        if(numberOfBooks() <= 0)
            return Optional.empty();

        Book longestTitleBook = books[0];
        for(int i=1 ; i<numberOfBooks() ; ++i) {
            final int curlen = books[i].getTitle().length();
            final int lnglen = longestTitleBook.getTitle().length();
            if(curlen > lnglen)
                longestTitleBook = books[i];
        }

        return Optional.of(longestTitleBook);
    }

    // 6.
    // Ouais c'est un peu intimidant, mais l'idée est simple.
    // Quand on tombe sur un livre égal à b, on l'échange avec le
    // dernier livre du tableau, et on décrémente book_count.
    // Ainsi, ça fait comme si on avait retiré le livre, et ça
    // évite de décaler toutes les cases.
    // Pour empêcher une boucle infinie si le dernier livre est aussi
    // égal à b, il faut prendre quelques précautions, d'où que le
    // corps de la boucle ne soit pas simple.
    // Ca peut "casser" l'ordre initial des livres, mais rien ne dit que
    // ArrayShoppingCart doit garder son contenu trié.
    public void removeAllOccurences(Book b) {
        Objects.requireNonNull(b);
        for(int i=0 ; i<book_count ; ++i) {

            if(!b.equals(books[i]))
                continue;

            // lasti devient l'index du book à échanger avec celui en i.
            int lasti = book_count-i;
            while(b.equals(books[lasti]) && lasti>0) 
                --lasti;

            if(lasti < i) {
                book_count = i;
                break;
            }

            books[i] = books[lasti];
            --book_count;
        }
    }
}
