import java.util.Scanner; 

public class Calc { 
	public static void main(String[] args) {
        // 1.
        // Scanner scanner = new Scanner(System.in);
        // System.out.println("Valeur : " + scanner.nextInt());
        //
        // 2.
        // System.out.println("Valeur : " + (new Scanner(System.in)).nextInt());
        //
        // 3. 
        // nextInt() est une méthode.
        //
        // 4. 
        // `import java.util.Scanner' sert à importer le package du même nom.
        // On rend la classe Scanner disponible à notre code.

        // 5.
        System.out.println("Veuillez entrer deux valeurs :");
		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		int b = scanner.nextInt();
        System.out.println("Somme     : " + (a+b));
        // 6.
        System.out.println("Différence: " + (a-b));
        System.out.println("Produit   : " + (a*b));
        System.out.println("Quotient  : " + (a/b));
        System.out.println("Reste     : " + (a%b));
	}
}
