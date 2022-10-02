public class LL {
    Node head;
   private int size;
   LL () {
       this.size = 0;
   }
    class Node{

        String data;
        Node next;
        Node(String data){
            this.data=data;
            this.next=null;
            size++;
        }
    }
    // add first,last
    public void addFirst(String data){
        Node newNode =new Node(data);
        if (head==null){
            head =newNode;
            return;
        }
        newNode.next =head;
        head =newNode;
    }
    public void addLast(String data){
        Node newNode =new Node(data);
        if (head==null){
            head =newNode;
            return;
        }
        Node currNode =head;
        while (currNode.next!=null) {
            currNode=currNode.next;
        }
        currNode.next=newNode;
    }
    public void printList(){
        if (head==null) {
            System.out.println("list is empty");
        }
        Node currNode =head;
        while (currNode!=null) {
            System.out.print(currNode.data+" -> ");
            currNode=currNode.next;
        }
        System.out.println("NULL");
    }
    public void deleteLast(){
        if(head ==null){
            System.out.println("the list is empty");
        }
        size--;
        if(head.next==null){
            head =null;
            return;
        }
        Node secondLast =head;
        Node lastNose =head.next;
        while (lastNose.next !=null) {
            lastNose =lastNose.next;
            secondLast =secondLast.next;
        }
        secondLast.next= null;
    }
    public void deleteFirst(){
        if(head ==null){
            System.out.println("the list is empty");
        }
        size--;
        if(head.next==null){
            head =null;
            return;
        }
        // Node secondLast =head;
        Node lastNose =head.next;
        head = lastNose;
        // while (lastNose.next !=null) {
        //     lastNose =lastNose.next;
        //     secondLast =secondLast.next;
        // }
        // secondLast.next= null;
    }
    public int get_size(){
        return size;
    }
    public void reverse(){
        if(head ==null || head.next ==null){
            return;
        }
        Node prev =head;
        Node cur =head.next;
        while (cur!=null) {
            Node nextNode =cur.next;
            cur.next =prev;
            prev =cur;
            cur =nextNode;
        }
        head.next =null;
        head = prev;
    }
    public Node reverseRecursive(Node head){
        if(head ==null || head.next ==null){
            return head;
        }
        Node newHead =reverseRecursive(head.next);
            head.next.next =head;
            head.next =null;
            return newHead;
    }
    public int search(String n){
        if (head ==null){
            System.out.println("The list is empty");
        }
        Node curr= head;int i=0;
        
        while (curr!=null) {
            if (curr.data==n){
                return i;
            }
            i++;
            curr =curr.next;
        }
        return -1;
    }
    public boolean searchRecursive(Node head,String n){
        if (head ==null){
            return false;
        }
        if (head.data==n){
            return true;
        }
        return searchRecursive((head.next), n);
    }
    public static void main(String[] args) {
        LL list =new LL();
        list.addFirst("LinkedList");
        list.addFirst("a");
        list.addFirst("is");
        list.addFirst("this");
        System.out.println(list.searchRecursive(list.head,"is"));
        list.printList();
        System.out.println();
    }
}
