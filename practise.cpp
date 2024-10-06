class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int k){
            val = k;
            left = NULL;
            right = NULL;
        }
};

class Btree{
    public :
        TreeNode*root;
        void preorder(TreeNode*);
};

void Btree::preorder(TreeNode*root){
    if(root == NULL){
        return;
    cout<<root->val;
    preorder(root->left);
    preorder(root->right);
}
}

int main(){
    Btree Bt;
    Bt.root = new TreeNode(1);
    Btree.root->left = new TreeNode(2);
    Btree.root->right = new TreeNode(3);
    Btree.root->left->left = new TreeNode(4);
    Btree.root->left->right = new TreeNode(5);
}
//======================

class car {
    constructur(brand,model){
        this.vehicleType= 'car',
        this.brand = brand,
        this.model = model
    }   
    drive() {
        return `Drivging a ${this.brand} ${this.model} car` 
    }
}

class bus{
    constructor() {

    }

}


