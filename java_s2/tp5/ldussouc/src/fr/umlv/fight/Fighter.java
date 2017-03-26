package fr.umlv.fight;

import java.util.Random;

public class Fighter extends Robot{
	
	// Un générateur pseudo-aléatoire va toujours générer 
	// la même série de nombre aléatoires, la seed permet de générer une série
	// différente selon le nombre.
	
	// si un champ est déclaré avec une visibilité publique, il peut accessible
	// par n'importe quelle autre classe d'un projet sans protection, ce n'est
	// pas sécurisé si l'on veut un contrôle parfait des champs d'une classe
	// En plus c'est pas bien pour l'encapsulation.
	
	// L'idée de sous-typage est qu'une méthode dépend de l'objet qui l'appelle,
	// son comportement est défini dans la classe de l'objet enfant même si elle existe
	// dans la classe parente
	
	// Le polymorphisme est l'idée de modifier une méthode d'un parent pour la rendre plus 
	// précise pour l'enfant.
	
	
	long seed;

	public Fighter(String name) {
		
		super(name);
		
		this.name = name;
		
		Random s = new Random();
		this.seed = s.nextInt();
	}
	
	@Override
    public String toString() {
        
		return ("Fighter " + this.name);
    };
    
    @Override
    protected boolean rollDice(){
		
    	Random r = new Random(this.seed);
		boolean dice = r.nextBoolean();
		
		return dice;
	}
}
