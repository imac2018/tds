package fr.umlv.geom;

public class Main {
    public static void main(String[] args) {
        System.out.println("\n--- TEST 1.6  ---\n"); test1_6();
        System.out.println("\n--- TEST 1.7  ---\n"); test1_7();
        System.out.println("\n--- TEST 1.8  ---\n"); test1_8();
        System.out.println("\n--- TEST 1.10 ---\n"); test1_10();
        System.out.println("\n--- TEST 1.11 ---\n"); test1_11();
        System.out.println("\n--- TEST 2.4  ---\n"); test2_4();
        System.out.println("\n--- TEST 2.5  ---\n"); test2_5();
        System.out.println("\n--- TEST 3.2  ---\n"); test3_2();
    }
    static void assertTrue(boolean b) {
        System.out.println("Censé être true : " + b);
    }
    static void assertEq(Object a, Object b) {
        System.out.println("Doivent être égaux : " + a + " et " + b);
    }
    static void assertNeq(Object a, Object b) {
        System.out.println("Ne doivent pas être égaux : " + a + " et " + b);
    }
    static void test1_6() {
        // 6. Translater le point de l'un le fait aussi pour l'autre !
        // C'est normal vu que le cercle se construit avec la référence du 
        // Point... Il faudrait faire un clone à la place.
        Point p = new Point(1, 2);
        Circle c = new Circle(p, 1);
        Circle c2 = new Circle(p, 2);
        c2.translate(1, 1);
        assertEq(c.getCenter(), c2.getCenter());
    }
    static void test1_7() {
        Point p = new Point(1, 2);
        Circle c = new Circle(p, 1);
        c.getCenter().translate(1,1);
        assertEq(p, c.getCenter());
    }
    static void test1_8() {
        Point p1 = new Point(1,2);
        Point p2 = new Point(3,4);
        Circle c1 = new Circle(p1, 42);
        Circle c2 = new Circle(p1, 42);
        Circle c3 = new Circle(p1, 32);
        Circle c4 = new Circle(p2, 42);
        assertTrue(c1.equals(c2));
        assertTrue(!c1.equals(c3));
        assertTrue(!c1.equals(c4));
    }
    static void test1_10() {
        Circle circle = new Circle(new Point(1,2), 42);
        Point inside = new Point(1,2);
        Point outside = new Point(43, 2);
        assertTrue(circle.contains(inside));
        assertTrue(!circle.contains(outside));
    }
    static void test1_11() {
        Circle c1 = new Circle(new Point(1,2), 42);
        Circle c2 = new Circle(new Point(43,200), 42);
        Circle c3 = new Circle(new Point(58,2), 10);
        Point p1 = new Point(1,2);
        Point p2 = new Point(43, 2);
        assertTrue(Circle.contains(p1, c1, c2, c3));
        assertTrue(!Circle.contains(p2, c3, c1, c2));
    }
    static void test2_4() {
        Ring r0 = new Ring(new Point(1,2), 42, 5);
        Ring r1 = new Ring(new Point(1,2), 42, 5);
        Ring r2 = new Ring(new Point(1,2), 42, 4);
        Ring r3 = new Ring(new Point(1,2), 13, 5);
        Ring r4 = new Ring(new Point(3,4), 42, 5);
        Circle c1 = new Circle(new Point(1,2), 42);
        Ring rx = new Ring(new Point(1,2), 42, 0);
        assertTrue(r0.equals(r1));
        assertTrue(!r1.equals(r2));
        assertTrue(!r1.equals(r3));
        assertTrue(!r1.equals(r4));
        assertTrue(!r1.equals(c1));
        assertTrue(!rx.equals(c1));
    }
    static void test2_5() {
        Point p=new Point(1,2);
        Circle c=new Circle(p,2);
        System.out.println(c);
        Ring r = new Ring(p, 2, 1);
        System.out.println(r);
    }
    static void test3_2() {
        // XXX tester les contains() de Rings
    }
}
