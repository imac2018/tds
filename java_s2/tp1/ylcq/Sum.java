import java.util.Scanner;
import java.util.Arrays;

public class Sum {
    // 1.
    public static int[] StringsToInts(String[] s) {
        int[] out = new int[s.length];
        for(int i=0 ; i<out.length ; ++i)
            out[i] = Integer.parseInt(s[i]);
        return out;
    }
    // 2.
    // static sert aux méthodes liées à une classe et non à une occurence
    // d'objet.
    // 
    // 3.
    // On a une jolie NumberFormatException.
    //
    // 4.
    public static int IntSum(int[] ints) {
        int sum = 0;
        for(int a : ints)
            sum += a;
        return sum;
    }
    // 5.
	public static void main(String[] args) {
        if(args.length <= 0)
            System.err.println("Warning : No argument was given.");
        System.out.println("integers: " + Arrays.toString(args));
        System.out.println("sum: " + IntSum(StringsToInts(args)));
	}
}
