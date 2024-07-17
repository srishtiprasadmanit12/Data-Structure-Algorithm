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

int main(){
    Btree Bt;
    Bt.root = new TreeNode(1);
    Btree.root->left = new TreeNode(2);
    Btree.root->right = new TreeNode(3);
    Btree.root->left->left = new TreeNode(4);
    Btree.root->left->right = new TreeNode(5);
}