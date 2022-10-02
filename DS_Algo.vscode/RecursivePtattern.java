public class RecursivePtattern {
    static void pattern1_rec(int n) {
        if (n > 0) {

            for (int i = 0; i < n; i++) {
                System.out.print("* ");
            }
            System.out.println();
            pattern1_rec(n - 1);
        }
    }

    public static void main(String[] args) {
        pattern1_rec(4);
    }
}
