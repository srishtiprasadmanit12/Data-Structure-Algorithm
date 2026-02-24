class TreeNode{
public:
    int val;
    TreeNode*left;
    TreeNode*right;
     TreeNode(int x){
        val = x;
        left=NULL;
        right=NULL;
     }
};
class BTree{
public:
    TreeNode* root;
};
//Iterative Approach
void itrInorder(TreeNode*root,vector<int>&inorder){
    stack<TreeNode*>stk;

    while(root!=NULL || !stk.empty()){
        while(root){
            stk.push(root);
            root=root->left;
        }
        root = stk.top();
        stk.pop();
        inorder.push_back(root->val);
        root = root->right;
    }
    return inorder;
}
/*
        1
    2       3
4       5
(n,n)

*/
//Recursive Approach
void inorderTraversal(TreeNode*root,vector<int>&ans){
    if(!root)
        return;
    inorderTraversal(root->left);
    ans.push_back(root->val);
    inorderTraversal(root->right);
}
vector<int> Inorder(TreeNode*root){
    if(!root)
         return {};
    inorderTraversal(root,ans);
    return ans;

}

int main(){
    //Create binary tree
     TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> result = Inorder(root);
    for (int x : result)
        cout << x << " ";
    vector<int> itrAns =  itrInorder(root,ans);
    for (int x : result)
        cout << x << " ";       
    return 0;
}