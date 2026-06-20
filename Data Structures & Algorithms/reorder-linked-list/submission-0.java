/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    private ListNode splitLL(ListNode head){
        if(head == null || head.next == null){
            return head;
        }

        ListNode slow = head.next;
        ListNode prev = head;
        ListNode fast = head.next.next;
        while(fast != null && fast.next != null){
            prev = prev.next;
            slow = slow.next;
            fast = fast.next.next;
        }
        
        prev.next = null;
        return slow;
    }

    private ListNode reverseLL(ListNode head){
        ListNode prev = null;
        ListNode curr = head;

        while(curr != null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    public void reorderList(ListNode head) {
        if(head == null || head.next == null)   return;

        ListNode LL2 = splitLL(head);
        LL2 = reverseLL(LL2);
        
        ListNode i = head;
        ListNode j = LL2;
        ListNode tmp1 = i.next;
        ListNode tmp2 = j.next;
        while(tmp1 != null && tmp2 != null){
            i.next = j;
            j.next = tmp1;
            i = tmp1;
            tmp1 = tmp1.next;
            j = tmp2;
            tmp2 = tmp2.next;
        }

        if(tmp1 == null){
            i.next = j;
        }
        else if(tmp2 == null){
            j.next = i;
        }

        while(head != null){
            System.out.print(head.val);
            head = head.next;
        }
    }
}
