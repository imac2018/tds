import java.util.Objects;

public class Book {
    private final String title, author;
    private final static String NO_AUTHOR = "<no author>";

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

    @Override
    public boolean equals(Object o) {
        if(o==null || !(o instanceof Book))
            return false;
        Book b = (Book)o;
        return title.equals(b.title) && author.equals(b.author);
    }

    @Override
    public String toString() {
        return title + (hasAuthor() ? " by " + author : "");
    }

    private boolean hasAuthor() {
        return author.equals(NO_AUTHOR) ? author==NO_AUTHOR : true;
    }

    public String getTitle() { return title; }
}
