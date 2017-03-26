package fr.umlv.calc;

public class Value implements Expr {
    private final int value;
    public Value(int v) {
        value = v;
    }
    public @Override String toString() {
        return value+"";
    }
    public int eval() {
        return value;
    }
}
