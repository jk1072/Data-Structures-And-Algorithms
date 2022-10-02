import java.util.Scanner;
public class Pattern {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int a =sc.nextInt();
            // int b =sc.nextInt();
            for (int i = 0; i < a; i++) {
                for (int j = 0; j<a; j++) {
                    if(j<i){
                        System.out.print("  ");
                    }
                    else{System.out.print("* ");}
                    
                }
                System.out.println();
            }
        }
    }
}
