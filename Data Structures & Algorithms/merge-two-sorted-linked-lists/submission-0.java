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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null)   return list2;
        if(list2 == null)   return list1;

        ListNode head = list1;
        ListNode i = head;
        ListNode j = head.next;
        ListNode k = list2;
        if(list1.val > list2.val){
            head = list2;
            i = head;
            j = head.next;
            k = list1;
        }

        while(k != null && j != null){
            if(j.val <= k.val){
                i.next = j;
                i = j;
                j = j.next;
            } else {
                i.next = k;
                i = k;
                k = k.next;
            }
        }

        if(k == null){
            i.next = j;
        }
        if(j == null){
            i.next = k;
        }

        return head;
    }
}