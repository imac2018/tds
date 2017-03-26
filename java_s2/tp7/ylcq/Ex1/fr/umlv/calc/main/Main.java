package fr.umlv.calc.main;
import fr.umlv.calc.OpOrValue;
import java.util.Scanner;

public class Main {
    // 4.
    public static void main(String[] args) {
        OpOrValue expression = new OpOrValue(OpOrValue.OP_ADD,
            new OpOrValue(2),
            new OpOrValue(3)
        );
        System.out.println(expression.eval());
        Scanner s = new Scanner(System.in);
        System.out.println("Type an expression...");
        System.out.println(OpOrValue.parse(s).eval());
        System.out.println("Type another expression...");
        System.out.println(OpOrValue.parse(s));
    }
}
