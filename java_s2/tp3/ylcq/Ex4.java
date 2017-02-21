import java.util.Arrays;

public class Ex4 {
    public static void main(String[] args) {
    	int[] foo = new int[]{1,5,2,6,8,2,3,5,7,5};
        System.out.println(Arrays.toString(foo));
    	sort(foo);
        System.out.println(Arrays.toString(foo));
    }
    // 1.
    public static void swap(int[] array, int i, int j) {
        int tmp  = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    // 2.
    // 3.
    public static int indexOfMin(int[] array, int i1, int i2) {
        if(i1 > i2)
            throw new IllegalArgumentException("(i1 <= i2) is expected!");

        int mini = i1;
    	for(int i=i1 ; i<i2 ; ++i)
	        if(array[i] < array[mini])
	            mini = i;

	    return mini;
    }
    // 4.
    public static void sort(int[] array) {
    	for(int i=0 ; i<array.length ; ++i)
	        swap(array, i, indexOfMin(array, i, array.length));
    }
}
