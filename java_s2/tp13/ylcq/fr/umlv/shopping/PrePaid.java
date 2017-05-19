package fr.umlv.shopping;

import java.util.Objects;

public class PrePaid extends ShoppingItem {
	private final int validTime;

	public PrePaid(int value, int validTime) {
        super(value);
        if(validTime >= 52)
            throw new IllegalArgumentException("Validité maximale: 1 an !");
        this.validTime = validTime;
	}

    @Override
	public int getPrice() {
        int value = super.getPrice();
		if (validTime <= 2) {   // si la validité est inférieure à 2 semaine,
			return value - value * 20 / 100; // -20% sur le prix
		}
		return value;
	}

	@Override
	public String toString() {
        int value = getPrice();
		return String.format("Carte cadeau (%d,%02d€), durée: %s semaines)", value/100, value%100, validTime);
	}
}
