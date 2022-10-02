public class Sum {
    static int foo(int x){
        // if (x==1){
        //     return 1;
        // }
        // return x+foo(x-1);
        int result=0;
        while (x!=0) {
            result+=x;
            x=x-1;
        }
        return result;
    }
    public static void main(String[] args) {
        System.out.println(foo(25));
    }
}
