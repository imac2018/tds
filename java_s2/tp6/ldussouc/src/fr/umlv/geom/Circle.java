package fr.umlv.geom;

public class Circle {
	
	private final Point centre;
	private int rayon;
	
	public Circle(Point centre, int rayon){
		
		// on crée un nouveau point pour éviter de translater
		// le point d'origine quand on translate le centre
		this.centre = new Point(centre.getX(),centre.getY());
		this.setRayon(rayon);
	}
	
	public int getRayon() {
		
		return this.rayon;
	}

	public void setRayon(int rayon) {

		this.rayon = rayon;
	}
	
    public Point getCentre() {
    	
        return centre;
    }
    
    public void translate(int dx, int dy) {
		
		this.centre.translate(dx, dy);	
	}

	public double surface(){
		
		return Math.PI * this.rayon * this.rayon; 
	}
	
	public boolean contains(Point p){
		
		if (((this.centre.getX() * this.centre.getX()) - (p.getX()*p.getX())) + ((this.centre.getY() * this.centre.getY()) - (p.getY()*p.getY())) == this.rayon* this.rayon)
			return true;
		else
			return false;
	}
	
	public boolean contains(Point p, Circle... circles){
		
		for(Circle c :circles)
			if (c.contains(p) == true)
				return true;
		
		return false;
	}
	
	@Override
	public String toString() {
		
		return "centre : " + this.centre.toString() + " rayon : " + this.getRayon() + " surface : " + this.surface();
	}
	
	@Override
	public boolean equals(Object obj) {
		if( !(obj instanceof Circle) || ((Circle) obj).getRayon() != this.rayon || ((Circle)obj).getCentre().equals(this.centre) == false)
			return false;
		else	
			return true;
	}
}