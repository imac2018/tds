import java.util.Optional;
import java.util.Objects;

public class ArrayShoppingCart {
    // 1. Non !
    private Book[] books;
    private int book_count;

    // 2.
    public ArrayShoppingCart(int max) {
        books = new Book[max];
        book_count = 0;
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
        sb.append("Number of books: ").append(numberOfBooks()).append("\n");
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

            swapBooksAt(i, lasti);
            --book_count;
            --i;
        }
    }
    public void swapBooksAt(int i, int j) {
        Book tmp = books[i];
        books[i] = books[j];
        books[j] = tmp;
    }
}
