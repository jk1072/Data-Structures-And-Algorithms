public class StaticDemo {
    public static void main(String[] args) {
        Abc.i=6;
        Abc.show();
    }
}
class Abc{
    static int i;
    public static void show(){
        System.out.println("hi");
        System.out.println(i);
    }
}
