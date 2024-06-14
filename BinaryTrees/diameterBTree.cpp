class Solution {
public:
int ans =0;
    int height(TreeNode* root){
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        ans = max(ans,lh+rh); // Calculate diameter separetly in 'ans' variable
        return 1+max(lh,rh); // return height recursively
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        height(root);

        return ans;
    }
};

/*
Important question to understand how we calculate diameter, we have to make two functions where in
we calculate height recursively at every node & hence dia = lh+rh hinged at every node.
*/