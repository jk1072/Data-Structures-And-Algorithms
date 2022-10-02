public class varArgs {
    static int foo(int t,int...arr){
        int result;
        if(arr[0]>arr[1]){
            result=t*(arr[0]*arr[1]);
        }
        else{
            result=t*(arr[0]+arr[1]);
        }
        return result;
    }
    static int foo(int x,int y){
        System.out.println("Hello World");
        return 0;
    }
    public static void main(String[] args) {
        int i= foo(7,7,2,3,1,6,7);
        foo(9,0);
        System.out.println(i);
    }
}
