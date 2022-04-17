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
    TreeNode *tmp;
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return root;
        TreeNode *dummy = new TreeNode(0);
        tmp = dummy;
        inorder(root);
        return dummy->right;
    }
    
    void inorder(TreeNode *root){
        if(!root)
            return;
        inorder(root->left);
        root->left=NULL;
        tmp->right=root;
        tmp=tmp->right;
        inorder(root->right);
    }
};