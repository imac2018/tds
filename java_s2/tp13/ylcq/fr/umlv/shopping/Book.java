package fr.umlv.shopping;

import java.util.Objects;

public class Book extends ShoppingItem {
	private final String author;
	private final String title;

	public Book(String author, String title, int price) {
        super(price);
		this.author = Objects.requireNonNull(author);
		this.title = Objects.requireNonNull(title);
	}

	@Override
	public String toString() {
		return title + ", de " + author;
	}

	@Override
	public boolean equals(Object o) {
		if (!(o instanceof Book)) {
			return false;
		}
		Book b = (Book) o;
		return getPrice() == b.getPrice() && title.equals(b.title) && author.equals(b.author);
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + author.hashCode();
		result = prime * result + getPrice();
		result = prime * result + title.hashCode();
		return result;
	}

    @Override
    public String toTextFormat() {
        return 
            SaverLoader.BOOK_TYPE
          + SaverLoader.SEPARATOR
          + getPrice()
          + SaverLoader.SEPARATOR
          + title
          + SaverLoader.SEPARATOR
          + author
          ;
    }
}
