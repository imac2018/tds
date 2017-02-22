import java.util.Arrays;

public class Sort {

    public static void swap(int[] array, int index1, int index2) {
        
        int temp  = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    public static int indexOfMin(int[] array, int index1, int index2) {

        int minTemp = index1;

    	for(int i=index1 ; i<index2 ; ++i){

	        if(array[i] < array[minTemp])
	            minTemp = i;
        }

	    return minTemp;
    }

    public static void sort(int[] array) {

    	for(int i = 0 ; i < array.length ; ++i)
	        swap(array, i, indexOfMin(array, i, array.length));
    }

    public static void main(String[] args) {

        int[] tab = new int[]{5,2,2,9,4};

        System.out.println("Tableau de base : " + Arrays.toString(tab));
        swap(tab, 4, 3);
        System.out.println(Arrays.toString(tab));  

        int min = indexOfMin(tab, 4, 3);
        System.out.println(min);      

        sort(tab);
        System.out.println(Arrays.toString(tab));  
    }

}
