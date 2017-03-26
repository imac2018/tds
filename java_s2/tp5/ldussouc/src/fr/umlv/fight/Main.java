package fr.umlv.fight;

public class Main {
	
	public static void main(String[] args) {
		
		Robot d2r2 = new Robot("d2r2");
		Robot data = new Robot("data");
		
		Fighter deLillo = new Fighter("Grégoire");
		Fighter eleve = new Fighter("Student");
		
		System.out.println(d2r2.toString());
		System.out.println(data.toString());
		
		System.out.println("Le gagnant est : " + Arena.fight(eleve, deLillo));
	}
}
