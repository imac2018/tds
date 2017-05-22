package fr.umlv.shopping;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.file.StandardOpenOption;
import java.nio.charset.Charset;
import java.util.List;
import java.util.ArrayList;

public class SaverLoader {
    public static final String SEPARATOR = "#";
    public static final String BOOK_TYPE = "B";
    public static final String VIDEO_GAME_TYPE = "G";
    public static final String PREPAID_TYPE = "P";

    public static void 
    saveInTextFormat(ShoppingCart items, BufferedWriter bw) 
    throws IOException
    {
        for(ShoppingItem item: items) {
            bw.write(item.toTextFormat());
            bw.newLine();
        }
    }

    public static ShoppingCart
    loadFromTextFormat(BufferedReader br) 
    throws IOException
    {
        ShoppingCart list = new ShoppingCart();
        for(;;) {

            String line = br.readLine();
            if(line == null)
                break;

            String[] parts = line.split(SEPARATOR);

            int price = Integer.parseInt(parts[1]);

            switch(parts[0]) {
            case BOOK_TYPE:
                { // Local scope
                    String title = parts[2];
                    String author = parts[3];
                    list.add(new Book(author, title, price));
                }
                break;
            case VIDEO_GAME_TYPE:
                String title = parts[2];
                VideoGame.Console console = VideoGame.Console.valueOf(parts[3]);
                list.add(new VideoGame(title, console, price));
                break;
            case PREPAID_TYPE:
                int validTime = Integer.parseInt(parts[2]);
                list.add(new PrePaid(price, validTime));
                break;
            }
        }
        return list;
    }
    public static void main(String[] args) 
    throws IOException
    {
        Book sdb = new Book("S. de Beauvoir", "Mémoires d'une jeune fille rangée", 990);
        VideoGame zelda = new VideoGame("The legend of Zelda", VideoGame.Console.WII, 4950);
        PrePaid pp100 = new PrePaid(10000, 10);        

        ShoppingCart list = new ShoppingCart();
        list.add(sdb);
        list.add(zelda);
        list.add(pp100);
        Path saveFilePath = Paths.get("saveFile.txt");
        try(BufferedWriter bw = Files.newBufferedWriter(saveFilePath, Charset.forName("UTF-8"), StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING)) {
            SaverLoader.saveInTextFormat(list, bw);
        }

        System.out.println("Written to `" + saveFilePath + "`:");
        System.out.println(sdb.toTextFormat());
        System.out.println(zelda.toTextFormat());
        System.out.println(pp100.toTextFormat());

        System.out.println();

        Path loadFilePath = Paths.get("saveInLatin15.txt");
        try(BufferedReader br = Files.newBufferedReader(loadFilePath, Charset.forName("ISO-8859-15"))) {
            ShoppingCart loaded = SaverLoader.loadFromTextFormat(br);
            System.out.println("Cart loaded from `" + loadFilePath + "`:");
            System.out.println(loaded);
        }
    }
}


