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
    bool validBSTLogic(TreeNode* root_t, pair<int, int> pr) {
        if(!root_t)   return true;

        if(!(root_t->val > pr.first && root_t->val < pr.second)){
            cout << pr.first << " << " << root_t->val << " << " << pr.second;
            return false;
        }

        bool left = true, right = true;
        if(root_t -> left)    left = validBSTLogic(root_t -> left, {pr.first, root_t -> val});
        if(root_t -> right)    right = validBSTLogic(root_t -> right, {root_t -> val, pr.second});

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return validBSTLogic(root, {INT_MIN, INT_MAX});
    }
};
