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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL) return 1;
        int l = INT_MAX, r = INT_MAX;
        //we'll check only if node is not null
        if(root->left)
             l = minDepth(root->left);
        if(root->right)
            r = minDepth(root->right);
        
         return 1+ min(l,r);
    }
};
/////////////////////////DFS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        int l = minDepth(root->left);
        int r = minDepth(root->right);

        if(l==0 || r==0) return max(l,r)+1; 

        return min(l,r)+1;
    }
};