// Time Complexity = O(logN)
class Solution {
public:
    int countNodes(TreeNode* root) {
       if(!root) return 0;

       if(!root->left && !root->right)
            return 1;
            
        int l = countNodes(root->left);
        int r = countNodes(root->right);
        
        return l+r+1;
    }
};

