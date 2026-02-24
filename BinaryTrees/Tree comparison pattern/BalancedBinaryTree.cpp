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

//Every node should be balanced isBalanced() function should be called on every node  

class Solution {
public:
    int subTreeHeight(TreeNode* node){
        if(node==NULL) return 0;
        int left = subTreeHeight(node->left);
        int right = subTreeHeight(node->right);
        return 1+max(left,right);

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        //
        int l = subTreeHeight(root->left);
        int r = subTreeHeight(root->right);
        if(abs(l-r)>1)
             return false;
        else 
            return isBalanced(root->left) && isBalanced(root->right); 
    }
};

