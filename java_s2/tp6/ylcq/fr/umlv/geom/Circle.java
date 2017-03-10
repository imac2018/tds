package fr.umlv.geom;

class Circle {
    // 2. On doit mettre private.
    private final Point center;
    private final int radius;
    // 3.
    public Circle(Point center, int radius) {
        this.center = new Point(center.getX(), center.getY());
        this.radius = radius;
    }
    // 4.
    public @Override String toString() {
        return "center: " + center + ", "
             + "radius: " + radius + ", "
             + "surface: " + surface();  // 9.
    }
    // 5.
    public void translate(int dx, int dy) {
        center.translate(dx, dy);
    }
    // 7. Le problème c'est qu'après, l'appelant peut modifier le "contenu"
    // du cercle par l'intermédiaire de la référence de Point renvoyée.
    // L'appelant peut tenir cette référence aussi longtemps qu'il le
    // souhaite ! Donc Ce N'est Pas Bien™
    public Point getCenter() {
        return new Point(center.getX(), center.getY());
    }
    // 8.
    public @Override boolean equals(Object o) {
        if(!(o instanceof Circle))
            return false;
        Circle other = (Circle)o;
        return center.equals(other.center) && radius==other.radius;
    }
    // 9.
    public float surface() {
        return (float)Math.PI*radius*radius;
    }
    // 10.
    public boolean contains(Point p) {
        int dx = p.getX() - center.getX();
        int dy = p.getY() - center.getY();
        return dx*dx + dy*dy <= radius*radius;
    }
    // 11. Wow ! Le '...' veut dire qu'on reçoit un nombre 
    // variable d'arguments !
    public static boolean contains(Point p, Circle... circles) {
        for(Circle c : circles)
            if(c.contains(p))
                return true;
        return false;
    }
}
