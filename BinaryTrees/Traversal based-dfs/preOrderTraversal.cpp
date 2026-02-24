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
//ITERATIVE APPROACH
vector<int>preOrder(TreeNode*root){
    vector<int>pre;
    stack<TreeNode*>stk;
    stk.push(root);

    while(!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();

        pre.push_back(node->val);
        if(node->right) stk.push(node->right);
        if(node->left)  stk.push(node->left);
    }
    return pre;
}
vector<int>postOrderRecur(TreeNode* root){
    stack<TreeNode*>stk;
    vector<int>ans;
    stk.push(root);
    while(!root || !stk.empty()){
        TreeNode* node = stk.pop();
        stk.pop();
        ans.push_back(node->val);

        if(node->left) stk.push(node->left);
        if(node->right) stk.push(node->right);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//RECURSIVE APPROACH
void preOrderRecur(TreeNode*root){
        if(!root){
        return;
    }
    ans.push_back(root->val);    
    preOrderRecur(root->left);
    preOrderRecur(root->right);
}

vector<int> recur(TreeNode* root){
    if(!root){
        return;
    }
    vector<int>ans = preOrderRecur(root,ans);
    return ans;
    
}