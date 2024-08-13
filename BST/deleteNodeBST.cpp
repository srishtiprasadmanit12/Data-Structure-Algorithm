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
    TreeNode* minNode(TreeNode*root){
        TreeNode*temp = root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL){
        return root;
       } 
       if(root->val > key){
            root->left =  deleteNode(root->left,key);
       }
       else if(root->val < key){
            root->right = deleteNode(root->right,key);
       }
       else{
            //no child
            if(root->left == NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //1 child
            //delete left
            if(root->left == NULL && root->right!=NULL){
                TreeNode*temp = root->right;
                delete root;
                return temp;
            }
            //delete right
            if(root->right == NULL && root->left!=NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            //2 child
            if(root->left!=NULL && root->right!=NULL){
                int minVal = minNode(root->right)->val;
                root->val=minVal;
                //Recursively again find the key=minVal 
                root->right = deleteNode(root->right,minVal);
                return root;
            }
       }
       return root;
    }
};