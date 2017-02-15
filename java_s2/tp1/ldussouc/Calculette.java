// on importe la classe Scanner du package util de Java
import java.util.Scanner; 

public class Calculette { 
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		System.out.println("Veuillez entrer deux valeurs :");

		// nextInt() est une méthode de la classe Scanner
		int nb1 = scanner.nextInt();
		int nb2 = scanner.nextInt();
		
		System.out.println("Somme      : " + (nb1+nb2));
        System.out.println("Différence : " + (nb1-nb2));
        System.out.println("Produit    : " + (nb1*nb2));
        System.out.println("Quotient   : " + (nb1/nb2));
        System.out.println("Reste      : " + (nb1%nb2));
	}
}