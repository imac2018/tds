package fr.umlv.shopping;

public abstract class ShoppingItem {
    private final int price;

    ShoppingItem(int price) {
		if (price < 0) {
			throw new IllegalArgumentException("Pas de prix négatif!");
		}
        this.price = price;
    }

    public int getPrice() {
        return price;
    }

    public abstract String toTextFormat();
}
