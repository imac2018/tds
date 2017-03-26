package fr.umlv.geom;

public class Main {

	public static void main(String[] args) {
		 
		Point p1 = new Point(1, 2);
		Circle c1 = new Circle(p1, 1);
	    
		// Il faut cloner le point pour pouvoir translater le point de c2
		// sans altérer le point de c1
		Point p2 = Point.clonePoint(p1);
		Circle c2 = new Circle(p2, 2);
	    
		Point p3 = Point.clonePoint(p1);
		Circle c3 = new Circle(p3, 3);
		
		System.out.println(c3.equals(c2));
		
	    c2.translate(1, 1);
	    
	    Point p = new Point(1, 2);
	    Circle c = new Circle(p, 1);
	    Ring r = new Ring(p, 2, 1);
	    
	    System.out.println(c);
	    System.out.println(r);
	   
	    c.getCentre().translate(1,1);
	    
	    System.out.println(p);
	    System.out.println(c);

	    System.out.println(c1 + "  " + c2);
	    
	}
}
