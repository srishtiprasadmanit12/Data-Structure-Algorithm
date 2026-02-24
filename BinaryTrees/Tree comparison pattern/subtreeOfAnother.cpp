class Solution {
public:
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot ||root->val != subRoot->val ) return false;
        return isSame(root->left,subRoot->left) && isSame(root->right , subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root ) return false;
        //check for every node , do this recursively
        if(isSame(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};