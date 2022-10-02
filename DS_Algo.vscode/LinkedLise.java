import java.util.*;
public class LinkedLise {
    public static void main(String[] args) {
        LinkedList<String> list =new LinkedList<String>();
        list.addFirst(("a"));
        list.addFirst(("is"));
        System.out.println(list);
        list.addFirst("this");
        System.out.println(list);
        LinkedList<Integer> list2 = new LinkedList<>();
       list2.add(1);
       list2.add(2);
       list2.add(1,3);
       System.out.println(list2);
       Collections.reverse(list2);
       System.out.println(list2);
    }
}
