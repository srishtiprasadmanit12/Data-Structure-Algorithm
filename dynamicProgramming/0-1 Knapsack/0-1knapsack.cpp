/*
Input: capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Bag can hold atmost 'capacity' weight 

Dry run:
maximum sum: ?
*/


int knapsack(int wt[],int val[],int W,int n){
    if(W==0 || n==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(wt,val,W,n-1);
    }
    else{
        return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1) , knapsack(wt,val,W,n-1));
    }
}

int unbounded_knapsack(int wt[],int val[],int W,int n){
    if(W==0 ){
        return 0;
    }
    if(n==0){
        return 0;
    }
    if(W<wt[n-1]){
        return unbounded_knapsack(wt,val,W,n-1);
    }
    else{
        return max(val[n-1] + unbounded_knapsack(wt,val,W-wt[n-1],n), unbounded_knapsack(wt,val,W,n-1));
    }
}

int unbounded_knapsack2(int wt[],int val[],int W,int n){
    if(W==0){
        return 0;
    }
    if(n==0){
        return 0;
        }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        if(W>wt[i])
            ans = max(val[i] + unbounded_knapsack2(wt,val,W-wt[i],n), ans);// max(include,exclude)
    }
    return ans;

}

int main(){

    int wt[] =  {4, 5, 1};
    int val[] = {1, 2, 3};
    int W=4;
    int n=3;

    return knapsack(wt,val,W,n);

}