package fr.umlv.calc;
import java.util.Objects;

abstract class BinOp implements Expr {
    final Expr left, right; // Non, je ne met pas ces champs privés.
    public BinOp(Expr l, Expr r) {
        left  = Objects.requireNonNull(l); 
        right = Objects.requireNonNull(r);
    }
    abstract String sym();
    public @Override String toString() {
        return "(" + left + " " + sym() + " " + right + ")";
    }
}
