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
    bool checkSubroot(TreeNode* root, TreeNode* subRoot)  {
        if(!root || !subRoot)   return (root == subRoot);

        bool left = checkSubroot(root -> left, subRoot -> left);
        bool right = checkSubroot(root -> right, subRoot -> right);

        return (
            (root -> val == subRoot -> val) &&
            left && right
        );
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return (root == subRoot);
        if(root -> val == subRoot -> val && checkSubroot(root, subRoot)) {
            return true;
        }

        bool left = isSubtree(root -> left, subRoot);
        bool right = isSubtree(root -> right, subRoot);

        return (left || right);
    }
};
