package fr.umlv.geom;

public class Main {
    // XXX Faire les tests de contain() de Circle !
    // XXX Test equals() de Ring !
    public static void main(String[] args) {
        test2_5();
    }
    static void test1_6() {
        // 6. Translater le point de l'un le fait aussi pour l'autre !
        // C'est normal vu que le cercle se construit avec la référence du 
        // Point... Il faudrait faire un clone à la place.
        Point p = new Point(1, 2);
        Circle c = new Circle(p, 1);
        Circle c2 = new Circle(p, 2);
        c2.translate(1, 1);
        System.out.println(c + " " + c2);
    }
    static void test2_5() {
        Point p=new Point(1,2);
        Circle c=new Circle(p,2);
        System.out.println(c);
        Ring r = new Ring(p, 2, 1);
        System.out.println(r);
    }
}
