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

	@Override
	public String toString() {
		return "(" + x + ',' + y + ')';
	}
	
    // 1.
    // Ca ne compile pas parce que x et y sont finaux.
    // Soit on ne met pas x et y comme 'final',
    // soit "translate()" renvoie un nouveau Point.
	public void translate(int dx, int dy) {
	  x += dx;
	  y += dy;
	}

    // 8.
    public @Override boolean equals(Object o) {
        if(!(o instanceof Point))
            return false;
        Point p = (Point)o;
        return x==p.x && y==p.y;
    }
}
