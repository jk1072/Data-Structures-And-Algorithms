public class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }

class Solution {
    public int size(ListNode head){
        if(head ==null){
            return 0;
        }
        ListNode cur = head; int i=0;
        while(cur!=null){
            i++;
            cur =cur.next;
        }
        return i;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head==null){
            return head;
        }
        if (head.next==null){
            return null;
        }



        ListNode prev =head;
        ListNode curr =head.next;
        int j= size(head)-n+1;
        if(j==1){
            head = curr;
            return head;
        }else if(j==2){
            prev.next=curr.next;
            return head;
        }else{
        for (int i = 0; i < j-2; i++) {
            prev =prev.next;
            curr =curr.next;
        }
        prev.next =curr.next;
        return head;}
        
    }
}
class Solution1 {
    public int size(ListNode head){
        if(head ==null){
            return 0;
        }
        ListNode cur = head; int i=0;
        while(cur!=null){
            i++;
            cur =cur.next;
        }
        return i;
    }
    public ListNode deleteMiddle(ListNode head) {
        if (head ==null){
            return head;
        }if (head.next==null) {
            return null;
        }
        int j= size(head)/2;
        ListNode prev =head;
        ListNode curr =head.next;
        for (int i = 0; i < j-1; i++) {
            prev =prev.next;
            curr =curr.next;
        }
        prev.next =curr.next;
        return head;

    }
}
class Solution3 {
    public int size(ListNode head){
        if(head ==null){
            return 0;
        }
        ListNode cur = head; int i=0;
        while(cur!=null){
            i++;
            cur =cur.next;
        }
        return i;
    }
    public void reorderList(ListNode head) {
        ListNode prev =head;
        if (head==null|| head.next==null|| head.next.next==null){
            head=prev;
        }else{

            int j= size(head)/2;
            ListNode curr =head.next;
            if (size(head)%2==0){
                for (int i = 0; i < j-1; i++) {

                for (int k = 0; k < size(head)-i-2; k++) {
                    curr =curr.next;
                }
                    prev.next =curr;
                    curr.next =prev.next;
                    prev =prev.next;
            }

        }
            if (size(head)%2!=0){
                for (int i = 0; i < j; i++) {

                for (int k = 0; k < size(head)-i-2; k++) {
                    curr =curr.next;
                }
                    prev.next =curr;
                    curr.next =prev.next;
                    prev =prev.next;
            }
        }
            
        }
    }
}
// Palindrome Question
class Solution8 {
    public ListNode getMiddle(ListNode head) {
   ListNode fast = head;
   ListNode slow = head;
   while (fast.next != null && fast.next.next != null) {
       fast = fast.next.next;
       slow = slow.next;
   }
   return slow;
}
 

public ListNode reverse(ListNode head) {
   ListNode prev = null;
   ListNode curr = head;
  
   while (curr != null) {
       ListNode next = curr.next;
       curr.next = prev;
       prev = curr;
       curr = next;
   }
   return prev;
}

   
    public boolean isPalindrome(ListNode head) {
   if(head == null || head.next == null) {
       return true;
   }
  
   ListNode firstHalfEnd = getMiddle(head);
   ListNode secondHalfStart = reverse(firstHalfEnd.next);
   ListNode firstHalfStart = head;
  
   while(secondHalfStart != null) {
       if(secondHalfStart.val != firstHalfStart.val) {
           return false;
       }
       secondHalfStart = secondHalfStart.next;
       firstHalfStart = firstHalfStart.next;
   }
  
   return true;
}


// Detecting Loop in a linked list
public boolean hasCycle(ListNode head) {
    ListNode slow = head;
    ListNode fast = head;
   
    while(fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
        if(fast == slow) {
            return true;
        }
    }
    return false;
 }
}
 