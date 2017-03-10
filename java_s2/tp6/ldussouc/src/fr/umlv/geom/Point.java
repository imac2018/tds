package fr.umlv.geom;

public class Point {
	
	private int x;
	private int y;

	public Point(int x, int y) {
		
		this.x = x;
		this.y = y;
	}

	public int getX() {
	
		return x;
	}

	public int getY() {
		
		return y;
	}
	
	public static Point clonePoint (Point p){
		  
		Point new_p = new Point(p.getX(), p.getY());
		return new_p;
	}

	@Override
	public boolean equals(Object obj) {
		
		if( !(obj instanceof Point) || ((Point)obj).getX() != this.x || ((Point)obj).getY() != this.y)
			return false;
		else
			return true;
	}

	@Override
	public String toString() {
		
		return "(" + x + ',' + y + ')';
	}
	
	// compilation impossible si les attributs sont créés avec le mot-clé final
	public void translate(int dx, int dy) {
	  
		x += dx;
		y += dy;
	}
}
