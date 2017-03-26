package fr.umlv.fight;

import java.util.Objects;

public class Arena {
	
	static public String fight(Robot r1, Robot r2){
		
		Objects.requireNonNull(r1);
		Objects.requireNonNull(r2);
		
		while(r2.isDead() == false && r1.isDead() == false){
			
			r1.fire(r2);
			
			if(r2.isDead() == false)
				r2.fire(r1);
			else if (r2.isDead() == true)
				return r1.toString();
		}
		
		return r2.toString();	
	}
}
