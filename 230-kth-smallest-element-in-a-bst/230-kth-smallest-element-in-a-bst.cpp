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
    int nth=0,res=0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return 0;
        kthSmallest(root->left,k);
        nth++;
        if(nth==k)
            res= root->val;
        kthSmallest(root->right,k);
        return res;
    }
};