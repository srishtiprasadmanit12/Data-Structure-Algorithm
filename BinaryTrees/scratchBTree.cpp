using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left,*right;
    TreeNode(int k){
        val = k;
    }
};

class Btree {
    public:
        TreeNode *root;
        void preOrder(TreeNode *);
};

void Btree::preOrder(TreeNode *root){
    if(root==NULL) return;

    cout<<root->val;
    preOrder(root->left);
    preOrder(root->right);
}

