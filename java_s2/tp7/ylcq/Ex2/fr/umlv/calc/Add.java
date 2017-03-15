package fr.umlv.calc;
import java.util.Objects;

public class Add extends BinOp {
    public Add(Expr l, Expr r) {
        super(l,r);
    }
    @Override String sym() { return "+"; }
    public int eval() {
        return left.eval() + right.eval();
    }
}
