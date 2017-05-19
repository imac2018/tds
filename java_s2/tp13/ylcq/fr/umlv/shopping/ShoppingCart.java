package fr.umlv.shopping;

import java.util.ArrayList;
import java.util.Objects;

public class ShoppingCart {
	private final ArrayList<ShoppingItem> cart;

	public ShoppingCart() {
		cart = new ArrayList<>();
	}

	public void add(ShoppingItem item) {
		cart.add(Objects.requireNonNull(item));
	}

	public void remove(ShoppingItem item) {
		cart.remove(item);
	}

	public int price() {
		int sum = 0;
		for(ShoppingItem item : cart) {
			sum += item.getPrice();
		}
		return sum;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("--- Shopping cart ---\n");
		for (ShoppingItem item : cart) {
			sb.append(item).append("\n");
		}
		sb.append("---------------------");
		return sb.toString();
	}
}
