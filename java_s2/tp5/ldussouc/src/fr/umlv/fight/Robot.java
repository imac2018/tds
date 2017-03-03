package fr.umlv.fight;

import java.util.Objects;

public class Robot {
	
	protected String name;
	protected int lifePoints;
	
	public Robot(String name) {
		
		Objects.requireNonNull(name);

		this.name = name;
		this.lifePoints = 10;
	}
	
	public String getName() {
		return name;
	}
	
	public int getLifePoints() {
		return lifePoints;
	}
	
	public void setLifePoints(int lifePoints) {
		this.lifePoints = lifePoints;
	}
	
	// ça c'était pas beau en vrai !
	/*protected boolean rollDice(){
		
		boolean dice = true;
		
		if(this instanceof Fighter){
			
			Random r = new Random( ((Fighter) this).seed );
			dice = r.nextBoolean();
		}
		
		return dice;
	}*/
	
	protected boolean rollDice(){
		
		boolean dice = true;
		return dice;
	}
	
	public void fire(Robot enemy) {
		
		Objects.requireNonNull(enemy);
		
		if(enemy.isDead() == true)
			throw new IllegalStateException(enemy.toString() + " is dead !");
		
		boolean dice = this.rollDice();
		
		if (dice == true){
			System.out.println(this.toString() + " a été touché par le " + enemy.toString());
			enemy.setLifePoints( enemy.getLifePoints() - 2 );	
		}
		
	}
	
	public boolean isDead(){
		
		if (this.lifePoints <= 0){
			
			System.out.println(this.toString() + " is dead !");
			return true;
		}
	
		return false;
	}
	
	@Override
    public String toString() {
        
		return ("Robot " + this.name);
    };
}
