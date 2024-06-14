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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if(!root->left && !root->right){
            //reached leaf node
            return targetSum == root->val;
        }
        // follow preorder approach
        bool leftSum = hasPathSum(root->left,targetSum-root->val);
        bool rightSum =  hasPathSum(root->right,targetSum-root->val);

        return leftSum || rightSum;
    }
};
/*      
Follows preorder approach , calculate sum at each node & update targetSum 
base condition is the most important to observe here.
*/