package fr.umlv.geom;

// 1.
// Hériter c'est bien.
// En fait on préfère la composition.

// 2.
public class Ring extends Circle {
    private final int internalRadius;
    // 3. Lancer une exception.
    public Ring(Point center, int radius, int internalRadius) {
        super(center, radius);
        this.internalRadius = internalRadius;
        if(internalRadius >= radius)
            throw new IllegalArgumentException("internalRadius must be strictly less than radius!");
    }
    // 4.
    public @Override boolean equals(Object o) {
        if(!(o instanceof Ring))
            return false;
        Ring r = (Ring)o;
        return internalRadius==r.internalRadius && super.equals(o);
    }
    // 5.
    public @Override String toString() {
        return super.toString() + ", internalRadius: " + internalRadius;
    }
    // 3.1.
    public @Override boolean contains(Point p) {
        Circle trou = new Circle(getCenter(), internalRadius);
        return super.contains(p) && !trou.contains(p);
    }
    // 3.2
    public static boolean contains(Point p, Ring... rings) {
        for(Ring r : rings)
            if(r.contains(p))
                return true;
        return false;
    }
    // 3.3
    // XXX ??? 

}
