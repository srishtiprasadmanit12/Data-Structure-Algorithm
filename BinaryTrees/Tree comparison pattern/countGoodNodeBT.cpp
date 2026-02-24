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
//////////////////////CORRECT/////////////////////////
class Solution {
public:
    void solve(TreeNode*root,int compare,int &ans){
        if(!root){
            return;
        }
        if(root->val>=compare){
            ans++;
            compare = root->val;
        }
        solve(root->left,compare,ans);
        solve(root->right,compare,ans);
    }
    int goodNodes(TreeNode* root) {
       int m = root->val;
       int ans=0;
       solve(root,root->val,ans);
       return ans; 
    }
};
///////////////////////////////WRONG BELOW//////////////////////////////
class Solution {
public:
    int cnt=0;
    void nodes(TreeNode*root,int value){
        if(root==NULL){
            return;
        }
        if(root->val>=value){
            cnt++;
        }
        nodes(root->left,value);
        nodes(root->right,value);

    }
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int val = root->val;
        nodes(root,val);
        return cnt;
    }
};
/*
        3,3
    1,3         4,3
3,3           1,3   5,3        

*/