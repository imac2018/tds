package fr.umlv.calc;
import java.util.Scanner;

public interface Expr {
    public int eval();

    public static Expr parse(Scanner s) {
        if(!s.hasNext())
            throw new IllegalStateException("Missing op or value !");

        String word = s.next();
        try {
            return new Value(Integer.parseInt(word, 10));
        } catch(NumberFormatException e) {
            Expr l = parse(s); // XXX Ca parse ou ça casse
            Expr r = parse(s);
            switch(word) {
            case "+": return new Add(l,r);
            case "-": return new Sub(l,r);
            }
            throw new IllegalStateException("Unknown op !");
        }
    }
}
