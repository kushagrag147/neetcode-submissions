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
    int preOrderIndex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hashMap;

        for (int i = 0; i < inorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }

        return getTree(preorder, inorder, hashMap, 0, inorder.size()-1);
    }

    TreeNode* getTree(vector<int>& preorder, vector<int>& inorder,unordered_map<int, int> &hashMap, int inorderStart, int inorderEnd) {
        if (preOrderIndex >= preorder.size() || inorderStart > inorderEnd) {
            return nullptr;
        }

        int nodeIndexInInorder = hashMap[preorder[preOrderIndex]];

        if (nodeIndexInInorder < inorderStart && nodeIndexInInorder > inorderEnd) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[preOrderIndex]);
        preOrderIndex++;
        root->left = getTree(preorder, inorder, hashMap, inorderStart, nodeIndexInInorder - 1);
        root->right = getTree(preorder, inorder, hashMap, nodeIndexInInorder + 1, inorderEnd);

        return root;
        // return nullptr;
    }
};
