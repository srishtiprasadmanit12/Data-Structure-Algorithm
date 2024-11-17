/*
input:"abc",
output:["", "a", "b", "ab", "c", "ac", "bc", "abc"]
*/
void subseq(string &s1,vector<string>&ans,int idx,string &s2){
    //base
    if(idx==s1.size()){
        ans.push_back(s2);
        return;
    }
    //include
    s2.push_back(s1[idx]);
    subseq(s1,ans,idx+1,s2);

    //exclude
    s2.pop_back(); //pop or remove
    subseq(s1,ans,idx+1,s2);
}
int main(){

    string s1="abc";
    vector<string>ans;
    string s2="";
    subseq(s1,ans,0,s2);
    
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}