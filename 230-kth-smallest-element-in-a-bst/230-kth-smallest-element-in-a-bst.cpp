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
    int nth=0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return 0;
        int left = kthSmallest(root->left,k);
        if(left)
            return left;
        nth++;
        if(nth==k)
            return root->val;
        return kthSmallest(root->right,k);
    }
};