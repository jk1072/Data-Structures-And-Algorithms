public class Matrix1 {
    public static void main(String[] args) {
        final int[][] matrix = {
            { 1, 2, 3 },
            { 4, 5,6},
            { 7, 8, 9 }
         };
        for (int[] is : matrix) {
            for (int i = 0; i < 3; i++) {
                System.out.print(is[i]+" ");
            }
            System.out.println();
        }
    }
}
