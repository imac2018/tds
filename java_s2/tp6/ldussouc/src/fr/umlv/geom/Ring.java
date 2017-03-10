package fr.umlv.geom;

public class Ring extends Circle{
	
	private int rayonInterne;
	
	public Ring(Point centre, int rayon, int rayonInterne) {
		
		super(centre, rayon);
		
		if(rayonInterne < rayon)
			this.rayonInterne = rayonInterne;
		else
			throw new IllegalArgumentException("Le rayon interne doit être inférieur au rayon");
	}
	
	public int getRayonInterne() {
	
		return rayonInterne;
	}
	
	@Override
	public boolean equals(Object obj) {
		
		if(obj instanceof Ring && super.equals(obj) && ((Ring)obj).getRayonInterne() == this.rayonInterne)
			return true;
		else
			return false;
	}
	
	@Override
	public String toString() {
		
		return super.toString() + " RI : " + this.rayonInterne;
	}
}
