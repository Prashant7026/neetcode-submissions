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

struct Compare {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a -> val > b -> val; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(auto i: lists) {
            pq.push(i);
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while(!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            temp -> next = top;
            if(top -> next != NULL) {
                pq.push(top -> next);
            }
            temp = temp -> next;
        }

        return ans -> next;
    }
};