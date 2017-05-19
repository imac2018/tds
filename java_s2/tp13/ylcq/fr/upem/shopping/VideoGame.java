package fr.umlv.shopping;

import java.util.Objects;

public class VideoGame {
	public enum Console {  // static par défaut.
		PS3, PS4, XBOX, WII, DS
	};

	private final String title;
	private final Console console;
	private final int price;

	public VideoGame(String title, Console console, int price) {
		if (price < 0) {
			throw new IllegalArgumentException("pas de prix négatif!");
		}
		this.price = price;
		this.title = Objects.requireNonNull(title);
		this.console = Objects.requireNonNull(console);
	}

	public int getPrice() {
		return price;
	}

	@Override
	public String toString() {
		return title + ", sur " + console.name();
	}
}
