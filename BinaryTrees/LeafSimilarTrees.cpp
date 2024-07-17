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
    vector<int>solve(TreeNode *root,vector<int>&vec){
        if(root==NULL){
            return vec;
        }
        if(!root->left && !root->right){
            vec.push_back(root->val);
        }
        solve(root->left,vec);
        solve(root->right,vec);

        return vec;

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2){
            return true;
        }
        if(!root1 ||!root2){
            return false;
        }
        vector<int>vec;
        vector<int>vec1 = solve(root1,vec);
        vec.clear();
        vector<int>vec2 = solve(root2,vec);
        if(vec1==vec2){
            return true;
        }
        return false;
    }
};