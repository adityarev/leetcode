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
private:
    int helper(TreeNode* node, bool isleft) {
        if (node != NULL) {
            if (node->left == NULL && node->right == NULL) {
                return isleft ? node->val : 0;
            }
            return helper(node->left, true) + helper(node->right, false);
        }
        return 0;
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};