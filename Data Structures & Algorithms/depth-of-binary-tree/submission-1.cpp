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
    int depthFunc(TreeNode* root, int i, int ans) {
        if(root == NULL)    return i;

        int left = depthFunc(root -> left, i+1, ans);
        int right = depthFunc(root -> right, i+1, ans);

        int maxNum = max(left, right);

        return max(ans, maxNum);

    }


    int maxDepth(TreeNode* root) {
        if(root == NULL)    return 0;

        return depthFunc(root, 0, INT_MIN);

    }
};
