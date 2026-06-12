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
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> nodes;

        if (root==nullptr) return nodes;
        q.push(make_pair(root, 0));

        while(!q.empty()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            if (nodes.size() <= temp.second) {
               nodes.resize(temp.second+1);
            }
            nodes[temp.second].push_back(temp.first->val);
            if (temp.first->left) {
                q.push(make_pair(temp.first->left, temp.second+1)); 
            }
            if (temp.first->right) {
                q.push(make_pair(temp.first->right, temp.second+1)); 
            }
        }

        return nodes;
    }
};
