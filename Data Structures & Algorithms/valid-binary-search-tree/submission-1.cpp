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
    bool isValidBST(TreeNode* root) {
        return isNodeValid(root, INT_MIN, INT_MAX);
    }

    bool isNodeValid(TreeNode* root, int minValue, int maxValue) {
        if (root == nullptr) {
            return true;
        }

        bool isRootValid = root->val < maxValue && root->val > minValue;

        return isRootValid && isNodeValid(root->left, minValue, min(maxValue, root->val)) && isNodeValid(root->right, max(minValue, root->val), maxValue);
    }
};
