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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)   return list2;
        if(list2 == NULL)   return list1;

        ListNode* head = list1;
        ListNode* temp = list1;
        ListNode* list1Next = NULL;
        ListNode* list2Next = NULL;
        if(list2 -> val < list1 -> val) {
            head = list2;
            temp = list2;
            list2 = list2 -> next;
            if(list2 -> next != NULL)   list2Next = list2 -> next;
            if(list1 -> next != NULL)   list1Next = list1 -> next;
        } else {
            list1 = list1 -> next;
            if(list1 -> next != NULL)   list1Next = list1 -> next;
            if(list2 -> next != NULL)   list2Next = list2 -> next;
        }

        while(list1 != NULL && list2 != NULL) {
            if(list1 -> val < list2 -> val) {
                cout<<"1";
                temp -> next = list1;
                temp = temp -> next;
                list1 = list1Next;
                if(list1Next != NULL)   list1Next = list1Next -> next;
                cout<<"1 end";
            } else if(list2 -> val < list1 -> val) {
                cout<<"2";
                temp -> next = list2;
                temp = temp -> next;
                list2 = list2Next;
                if(list2Next != NULL)   list2Next = list2Next -> next;
                cout<<"2 end";
            } else {
                cout<<"3";
                temp -> next = list1;
                temp = temp -> next;
                list1 = list1Next;
                if(list1Next != NULL)   list1Next = list1Next -> next;
                cout<<"3 end";
            }
        }

        if(list1 != NULL) {
            temp -> next = list1;
        }

        if(list2 != NULL) {
            temp -> next = list2;
        }

        return head;
    }
};
