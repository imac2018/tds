package fr.umlv.shopping;

import java.util.Objects;
import java.util.Optional;

public class VideoGame extends ShoppingItem {
	public enum Console {  // static par défaut.
        PS3, PS4, XBOX, WII, DS
	};

	private final String title;
	private final Console console;

	public VideoGame(String title, Console console, int price) {
        super(price);
		this.title = Objects.requireNonNull(title);
		this.console = Objects.requireNonNull(console);
	}

	@Override
	public String toString() {
		return title + ", sur " + console.name();
	}

    @Override
    public String toTextFormat() {
        return 
            SaverLoader.VIDEO_GAME_TYPE
          + SaverLoader.SEPARATOR
          + getPrice()
          + SaverLoader.SEPARATOR
          + title
          + SaverLoader.SEPARATOR
          + console
          ;
    }
}
