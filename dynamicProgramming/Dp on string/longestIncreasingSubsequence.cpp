//RECUSIVE APPROACH
int lis_recursion(int arr[],int i){
    int res = 1;

    for(int j=0;j<i;j++){
        if(arr[i]>arr[j]){
            res= max(res,lis(arr,j)+1);
            
        }
    }
    return res;
}
//MEMOISED APPROACH
int lis_memo(int arr[],int i){
     int res = 1;

    for(int j=0;j<i;j++){
        if(arr[i]>arr[j]){
            res= max(res,lis(arr,j,dp)+1);
            
        }
    }
    return dp[i]=res;
}

int lis_iterative(int arr[],int n){
    if(n<=1)
        return n;
    vector<int>lis(n,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                lis[i]=lis[j]+1;
            }
        }
    } 
    //Maximum elemngt from the array
    int ans = *max_element(lis.begin(),lis.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1,-1);
    int ans=0;
    for(int i=0;i<n;i++){
        // ans = max(ans,lis_recursion(arr,i));
        ans = max(ans,lis_memo(arr,i,dp));
    }
    lis_iterative(arr,n);
    return ans;
}