class Node {
public:
    int val;
    Node*left;
    Node *right;
    Node *next;

    Node(int k){
        val=k;
        left=right=next=NULL;
    }
};

// Time - O(N)  && space -  O(N)
class Solution{
    public:
        Node*connect(Node*root){
            if(root==NULL) return NULL;
            queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                int n=q.size();
                for(int i=0;i<n;i++){
                    Node*temp=q.front();
                    q.pop();
                    if(i!=n-1) temp->next=q.front(); ///this is everything we need fig.out to solve this ques 
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
             return root;
        }

        };
// Time - O(N)  && space -  O(N) ; RECURSIVE APPROACH
class Solution{
    public:
        Node*connect(Node*root){

            if(root==NULL) return NULL; //Base case
            if(root->left) 
                root->left->next=root->right;
            if(root->right && root->next)
                root->right->next=root->next->left;
            connect(root->left);
            connect(root->right);

            return root;
        }
};

/*
            1
        2       3
    4      5   6    7

*/
// Time - O(N)  && space -  O(1) ; ITERATIVE APPROACH



int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution obj; //since we want to return whole tree

}