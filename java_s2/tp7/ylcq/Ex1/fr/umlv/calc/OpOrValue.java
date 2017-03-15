package fr.umlv.calc;
import java.util.Objects;
import java.util.Scanner;

public class OpOrValue {
    public static final int OP_NONE = 0;
    public static final int OP_ADD = 1;
    public static final int OP_SUB = 2;
  
    private final int operator;
    private final int value;
    private final OpOrValue left;
    private final OpOrValue right;
  
    // 1.
    // Il est déclaré private car il :
    // - Il n'est utilisé qu'en interne, pour ne pas copier-coller du code;
    // - Il est trop complexe pour être exposé publiquement
    private OpOrValue(int operator, int value, OpOrValue left, OpOrValue right) {
        this.operator = operator;
        this.value = value;
        this.left = left;
        this.right = right;
    }
    public OpOrValue(int value) {
        this(OP_NONE, value, null, null);
    }
    // XXX Faut-il cloner left et right ?
    public OpOrValue(int operator, OpOrValue left, OpOrValue right) {
        this(operator, 0,
            Objects.requireNonNull(left),
            Objects.requireNonNull(right)
        );
    }
  
    public int eval() {
        switch(operator) {
        case OP_ADD:
              return left.eval() + right.eval();
        case OP_SUB:
              return left.eval() - right.eval();
        default: // case OP_NONE:
              return value;
        }
    }
  
    // 3.
    // 6. Il faut utiliser Iterator.
    public static OpOrValue parse(Scanner s) {
        while(!s.hasNext())
            throw new IllegalStateException("Missing op or value !");

        String word = s.next();
        try {
            return new OpOrValue(Integer.parseInt(word, 10));
        } catch(NumberFormatException e) {
            int op = OP_NONE;
            switch(word) {
            case "+": op = OP_ADD; break;
            case "-": op = OP_SUB; break;
            default: throw new IllegalStateException("Unknown op !");
            }
            OpOrValue l = parse(s);
            return new OpOrValue(op, l, parse(s));
        }
    }
    // 5.
    public @Override String toString() {
        switch(operator) {
        case OP_ADD: return "(" + left + " + " + right + ")";
        case OP_SUB: return "(" + left + " - " + right + ")";
        }
        return value+"";
    }
}
