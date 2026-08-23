/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        queue<TreeNode*> q;

        q.push(root);
        TreeNode* last = q.back();
        vector<int> temp;
        while(!q.empty()) {
            TreeNode* topElement = q.front();
                temp.push_back(topElement->val);
                if(topElement -> left)  q.push(topElement -> left);
                if(topElement -> right)  q.push(topElement -> right);
                if(last == topElement) {
                    ans.push_back(temp);
                    last = q.back();
                    temp.clear();
                }
            q.pop();
        }

        return ans;
    }
};
