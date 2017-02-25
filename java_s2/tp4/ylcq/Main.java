import java.util.Optional;

public class Main {
    public static void main(String[] args) {
        Book[] books = getSomeBookArray();
        Book[] no_books = new Book[0];
        System.out.println("\n\n--- TEST ArrayShoppingCart (quelques livres) ---\n");
        testArrayShoppingCart(books);
        System.out.println("\n\n--- TEST ArrayShoppingCart (aucun livre) ---\n");
        testArrayShoppingCart(no_books);
        System.out.println("\n\n--- TEST FreeShoppingCart (quelques livres) ---\n");
        testFreeShoppingCart(books);
        System.out.println("\n\n--- TEST FreeShoppingCart (aucun livre) ---\n");
        testFreeShoppingCart(no_books);
    }

    private static Book[] getSomeBookArray() {
        Book b0 = new Book("50 nuances de Java", "Jean-Pierre Coffe");
        Book b1 = new Book("Chérie", "Arthur Ducoux");
        Book b2 = new Book("La vérité derrière les jeudilives", "Lucas Dussouchaud");
        Book b3 = new Book("Arrêtez de triquiter le C++", "Bjarne Stroustrup");
        Book b4 = new Book("Ca te manque les cours de C ?", "Corentin Deux chôment");
        return new Book[]{b0,b1,b2,b2,b3,b2,b0,b2,b4,b2};
    }

    private static void testLongestTitle(Optional<Book> ob) {
        if(ob.isPresent())
            System.out.println("Le livre au titre le plus long : `"+ ob.get() +"'");
        else
            System.out.println("Il n'y a pas de livre au titre le plus long !");
    }
    private static void testFreeShoppingCart(Book[] books) {
        FreeShoppingCart cart = new FreeShoppingCart();
        for(Book b : books)
            cart.add(b);
        cart.displayContents();

        testLongestTitle(cart.longestTitle_Index());
        testLongestTitle(cart.longestTitle_Iterator());
        testLongestTitle(cart.longestTitle());

        if(books.length < 3)
            return;

        Book removeMe = books[2];
        System.out.println("Retiré la 1ère occurence de `"+removeMe+"'...");
        cart.removeFirstOccurence(removeMe);
        System.out.println("Retiré la 1ère occurence de `"+removeMe+"'...");
        cart.removeFirstOccurence_Iterator(removeMe);
        cart.displayContents();
    }
    private static void testArrayShoppingCart(Book[] books) {
        ArrayShoppingCart cart = new ArrayShoppingCart(books.length);
        for(Book b : books)
            cart.add(b);
        cart.displayContents();

        testLongestTitle(cart.longestTitle());

        if(books.length < 3)
            return;

        Book removeMe = books[2];
        cart.removeAllOccurences(removeMe);
        System.out.println("\nRetiré tous les `"+removeMe+"'...\n");
        cart.displayContents();
    }
}
