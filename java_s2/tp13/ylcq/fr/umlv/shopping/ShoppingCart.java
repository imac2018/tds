package fr.umlv.shopping;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Iterator;
import java.util.HashMap;

public class ShoppingCart implements Iterable<ShoppingItem> {
	private final ArrayList<ShoppingItem> cart;
    // Ex 4
    private final HashMap<ShoppingItem, Integer> items_counts;

	public ShoppingCart() {
		cart = new ArrayList<>();
        items_counts = new HashMap<>();
	}

	public void add(ShoppingItem item) {
        Objects.requireNonNull(item);
        Integer cnt = items_counts.get(item);
        if(cnt == null) {
            cart.add(item);
            items_counts.put(item, 1);
        } else {
            items_counts.put(item, cnt+1);
        }
	}

	public void remove(ShoppingItem item) {
        Integer cnt = items_counts.get(item);
        if(cnt == null)
            return;
        if(cnt > 1) {
            items_counts.put(item, cnt-1);
        } else {
            items_counts.remove(item, cnt-1);
    		cart.remove(item);
        }
	}

    public int price() {
        return cart.stream().mapToInt( (item) -> {
            int count = items_counts.get(item);
            int total = item.getPrice() * count;
            return count > 1 ? total - total*5/100 : total;
        }).sum();
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

    public Iterator<ShoppingItem> iterator() {
        return cart.iterator();
    }
}
