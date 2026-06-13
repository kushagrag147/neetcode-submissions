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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        inOrderTraversal(root, nodes);

        return nodes[k-1];
    }

    void inOrderTraversal(TreeNode* root, vector<int> &nodes) {
        if (root != nullptr) {
            inOrderTraversal(root->left, nodes);
            nodes.push_back(root->val);
            inOrderTraversal(root->right, nodes);
        }
    }
};
