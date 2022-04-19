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
    TreeNode *prev,*first,*middle,*last;
    
    void inorder(TreeNode *root){
        if(!root)
            return;
        inorder(root->left);
        if(first == NULL && root->val < prev->val){
            first=prev;
            middle=root;
            
        }
        else if (first && root->val < prev->val)
            last = root;
        prev=root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(last)
            swap(first->val,last->val);
        else
            swap(first->val,middle->val);
    }
};