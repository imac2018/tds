package ex2;

import java.util.Objects;

public class Book {

    // Exercice 1

    final private String title;
    final private String author;

    public Book(String title) {

        this(title, "<no author>");
    }

    public Book(String title, String author) {

        this.title  = Objects.requireNonNull(title, "title cannot be null");
        this.author = Objects.requireNonNull(author, "author cannot be null");
    }

    public String getTitle() {

        return this.title;
    }

    public String getAuthor() {

        return this.author;
    }

    // Exercice 2

    @Override
    public boolean equals(Object b) {

        if (!(b instanceof Book))
            return false;

        Book book = (Book) b;

        return this.title.equals(book.getTitle()) && this.author.equals(book.getAuthor());

    }

    // Exercice 3

    public String toString() {

        return this.title + " by " + this.author;
    }
}
