/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reachlast(ListNode*& prev, ListNode*& last) {
        while(last != NULL && last -> next != NULL) {
            if(last != NULL)    last = last -> next;
            if(prev != NULL)    prev = prev -> next;
        }
    }

    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* tempNxt = head -> next;
        ListNode* prev = head;
        ListNode* last = head -> next;

        reachlast(prev, last);

        while(temp -> next != NULL) {
            temp -> next = last;
            if(temp != prev)    prev -> next = NULL;
            if(last != NULL && temp != prev)    last -> next = tempNxt;
            temp = tempNxt;
            tempNxt = tempNxt -> next;

            prev = head;
            last = head -> next;

            reachlast(prev, last);
        }
    }
};
