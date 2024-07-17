class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.

    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            pair<Node*,int>temp = q.front();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            q.pop();
            
            if(mp.find(hd)==mp.end()){
                mp[hd]=frontNode->data;
            }
            if(frontNode->left){
                q.push({frontNode->left,hd-1});
            }
            if(frontNode->right){
                q.push({frontNode->right,hd+1});
            }
            
        }
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
             
    }
};

/*
README TOP VIEW 
1. we need to understand requirement,that is finding top view , if we find once that value is only considered
we don't have to overwrite once we have got the value.

2.now how to implement this :
we can use map to store the value and the horizontal distance of the node.
we can use queue to traverse the tree level by level.
we can use the horizontal distance to find the top view of the tree.

push root node with hd in queue
while queue is not empty we'll iterate
capture frontnode and its hd
remove this node from queue
check if this node value is present in map or not, if not then only update map with hd & node value
traverse to left & right of BT 
iterate in map for seconf vlaue & push all node in same in vector  return the vector

*/