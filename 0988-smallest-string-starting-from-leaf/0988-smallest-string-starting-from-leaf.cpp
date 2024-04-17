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
    void dfs(TreeNode* node, string& ans, const string prev) {
        string curr(1, (char)('a' + node->val));
        curr += prev;
        if (node->left == NULL && node->right == NULL) {
            if (ans == "" || curr < ans) {
                ans = curr;
            }
            return;
        }
        if (node->left != NULL) {
            dfs(node->left, ans, curr);
        }
        if (node->right != NULL) {
            dfs(node->right, ans, curr);
        }
    }
    
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        dfs(root, ans, "");
        return ans;
    }
};