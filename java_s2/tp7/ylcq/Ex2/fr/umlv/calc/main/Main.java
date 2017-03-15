package fr.umlv.calc.main;
import fr.umlv.calc.Expr;
import fr.umlv.calc.Add;
import fr.umlv.calc.Sub;
import fr.umlv.calc.Value;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Expr expression = new Add(new Value(2), new Value(3));
        System.out.println(expression.eval());
        Scanner s = new Scanner(System.in);
        System.out.println("Type an expression...");
        System.out.println(Expr.parse(s).eval());
        System.out.println("Type another expression...");
        System.out.println(Expr.parse(s));
    }
}
