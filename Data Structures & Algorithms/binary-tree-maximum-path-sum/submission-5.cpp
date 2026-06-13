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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        
        int sum = maxSumNode(root);
        // cout<<"Sum: "<<sum<<"\n";
        return maxSum;
    }

    int maxSumNode(TreeNode* root) {
        if (root == nullptr) {
            return INT_MIN;
        }

        int maxLeftSum = maxSumNode(root->left);
        int maxRightSum = maxSumNode(root->right);

        // cout<<root->val<<" "<<maxLeftSum<<" "<<maxRightSum<<"\n";

        int nodeWithLeft = maxLeftSum == INT_MIN ? root->val : root->val + maxLeftSum;
        int nodeWithRight = maxRightSum == INT_MIN ? root->val : root->val + maxRightSum;
        int nodeWithRightAndLeft = maxLeftSum == INT_MIN ? (nodeWithRight) : (maxRightSum == INT_MIN ? nodeWithLeft : root->val + maxRightSum + maxLeftSum);

        maxSum = max(maxSum, max(max(max(max(max(maxLeftSum, maxRightSum), nodeWithLeft), nodeWithRight), nodeWithRightAndLeft), root->val)) ;
        // cout<<"Node: "<<root->val<<" "<<maxSum<<"\n";
        return max(max(nodeWithLeft, nodeWithRight), root->val);
    }
    
};
