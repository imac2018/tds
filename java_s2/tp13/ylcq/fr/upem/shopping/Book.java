package fr.umlv.shopping;

import java.util.Objects;

public class Book {
	private final String author;
	private final String title;
	private final int price;

	public Book(String author, String title, int price) {
		if (price < 0) {
			throw new IllegalArgumentException("pas de prix négatif!");
		}
		this.price = price;
		this.author = Objects.requireNonNull(author);
		this.title = Objects.requireNonNull(title);
	}

	public int getPrice() {
		return price;
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
		return price == b.price && title.equals(b.title) && author.equals(b.author);
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + author.hashCode();
		result = prime * result + price;
		result = prime * result + title.hashCode();
		return result;
	}
}