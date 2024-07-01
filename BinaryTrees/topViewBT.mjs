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