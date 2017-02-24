import java.util.Optional;

public class Main {
    public static void main(String[] args) {

        final int cnt = 100;
        ArrayShoppingCart cart = new ArrayShoppingCart(cnt);

        Book[] books = new Book[] {
        new Book("50 nuances de Java", "Jean-Pierre Coffe"),
        new Book("Chérie", "Arthur Ducoux"),
        new Book("La vérité derrière les jeudilives", "Lucas Dussouchaud"),
        new Book("Arrêtez de triquiter le C++", "Bjarne Stroustrup"),
        new Book("Ca te manque les cours de C ?", "Corentin Deux chôment")
        };

        for(Book b : books)
            cart.add(b);
        cart.add(books[2]);
        cart.add(books[3]);
        cart.add(books[2]);

        cart.displayContents();

        Optional<Book> lng = cart.longestTitle();
        if(lng.isPresent())
            System.out.println("Le livre au titre le plus long : `"+ lng.get() +"'");

        Book removeMe = books[2];
        cart.removeAllOccurences(removeMe);
        System.out.println();
        System.out.println("Removed all instances of `"+removeMe+"'...");
        System.out.println();
        cart.displayContents();
    }
}
