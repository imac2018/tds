import java.util.Scanner;
import java.util.Arrays;

public class Sum {

    // On appelle une classe statique pour qu'elle puisse être utilisée
    // par un programme externe sans instancier d'objet
    // Si l'argument n'est pas un nombre on a une exception :  NumberFormatException
    public static int[] stringsToInt(String[] s) {
        
        int[] tab = new int[s.length];
        
        for(int i = 0 ; i < tab.length ; ++i)
            tab[i] = Integer.parseInt(s[i]);

        return tab;
    }

    public static int sum(int[] tab) {
        
        int sum = 0;
        
        for(int a : tab)
            sum += a;
        
        return sum;
    }

	public static void main(String[] args) {

        System.out.println("integers : " + Arrays.toString(args));
        System.out.println("sum : " + sum(stringsToInt(args)));
	}
}
