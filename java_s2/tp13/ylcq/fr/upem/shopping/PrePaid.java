package fr.umlv.shopping;

import java.util.Objects;

public class PrePaid {
	private final int value;
	private final int validTime;

	public PrePaid(int value, int validTime) {
		this.value = value;
		this.validTime = Objects.checkIndex(validTime, 52); // validité maximale: 1 an
	}

	public int getPrice() {
		if (validTime <= 2) {   // si la validité est inférieure à 2 semaine,
			return value - value * 20 / 100; // -20% sur le prix
		}
		return value;
	}

	@Override
	public String toString() {
		return String.format("Carte cadeau (%d,%02d€), durée: %s semaines)", value/100, value%100, validTime);
	}
}