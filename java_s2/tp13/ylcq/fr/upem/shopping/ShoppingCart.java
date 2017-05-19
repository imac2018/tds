package fr.umlv.shopping;

import java.util.ArrayList;
import java.util.Objects;

public class ShoppingCart {
	private final ArrayList<Book> cart;

	public ShoppingCart() {
		cart = new ArrayList<>();
	}

	public void add(Book book) {
		cart.add(Objects.requireNonNull(book));
	}

	public void remove(Book book) {
		cart.remove(book);
	}

	public int price() {
		int sum = 0;
		for(Book b : cart) {
			sum += b.getPrice();
		}
		return sum;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("--- Shopping cart ---\n");
		for (Book book : cart) {
			sb.append(book).append("\n");
		}
		sb.append("---------------------");
		return sb.toString();
	}
}