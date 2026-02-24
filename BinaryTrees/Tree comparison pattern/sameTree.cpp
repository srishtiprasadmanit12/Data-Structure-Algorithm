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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //check for null
        if(p==NULL && q==NULL) return true;
        if(p==NULL &&q!=NULL)
            return false;
        if(p!=NULL && q==NULL)
            return false;
        //base condition
        if(p->val != q->val)
            return false;
            
         //recursively check if left & right subtrees are same
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};
/*
    1
 2      3
4 5

*/