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
    private int LengthOfLL(ListNode head){
        int count = 0;
        while(head != null){
            count++;
            head = head.next;
        }

        return count;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int tmp = LengthOfLL(head) - n;
        ListNode i = head;
        if(tmp == 0)  return head.next;

        while(tmp > 1){
            i = i.next;
            tmp--;
        }

        if(i.next != null){
            i.next = i.next.next;
        } else {
            i.next = null;
        }

        return head;
    }
}
