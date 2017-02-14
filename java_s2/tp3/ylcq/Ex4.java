public class Ex4 {
    public static void main(String[] args) {
    }
    // 1.
    public static void swap(int[] array, int index1, int index2) {
        int tmp = array[index1];
        array[index1] = array[index2];
        array[index2] = tmp;
    }
    // 2.
    // 3.
    public static int indexOfMin(int[] array, int i1, int i2) {
        
    }
    // 4.
    public static void sort(int[] array) {
        //trouver le min
        //swap()
        sort(array, 0, array.length);
    }
    private static void sort(int[] array, int l, int r) {
        if(l >= r)
            return;
        if(l == r-1) {
            int i = indexOfMin(array, l, r);
            int j = i==l ? r : l;
            swap(array, i, j);
            return;
        }
        int m = l+(r-l)/2;
        sort(array, l, m);
        sort(array, m, r);
    }

}
