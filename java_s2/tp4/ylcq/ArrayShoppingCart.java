import java.util.Optional;

public class ArrayShoppingCart {
    // 1. non !
    private Book[] books;
    private int book_count;

    // 2.
    public ArrayShoppingCart(int max) {
        books = new Book[max];
        book_count = 0;
    }
    public ArrayShoppingCart() { this(100); }
    public void add(Book b) {
        if(book_count >= books.length)
            throw new IllegalStateException("Limite dépassée, impossible de faire l'ajout");
        books[book_count++] = b;
    }
    // Dans le main(), le test cause une ArrayIndexOutOfBoundsException.
    // Il faut que add() lance une exception appropriée, plus explicatrice.
    //
    // 3.
    public int numberOfBooks() { return book_count; }

    // 4.
    // XXX Implémenter toString() et s'en servir à la place !
    public void displayContents() {
        System.out.println("Number of books: " + numberOfBooks());
        for(int i=0 ; i<numberOfBooks() ; ++i)
            System.out.println(books[i]);
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
    public void removeAllOccurences(Book b) {
        for(int i=0 ; i<numberOfBooks() ; ++i) {
            if(!b.equals(books[i]))
                continue;
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
