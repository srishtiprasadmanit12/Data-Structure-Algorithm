
//burte force approach : using nested loop
class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int n = s.size();
	    int maxDiff = INT_MIN;
	    bool hasZero = false;
	    
	    //iterate over all possible starting point
	    for(int i=0;i<n;i++){
	        int zero=0,one=0;
	        //iterate over all possible ending point
	        for(int j=i;j<n;j++){
	            if(s[j]=='0'){
	                zero++;
	                hasZero=true;
	            }else{
	               one++;
	            }
	        int diff = zero-one;
    	    maxDiff = max(maxDiff,diff);
	        }
    	    
	    }
        return hasZero?maxDiff:-1;
	}
};

//kadens algo approach : single loop
class Solution{
public:	
	int maxSubstring(string s)
	{
	    int n=s.size();
	    int maxDiff = INT_MIN;
	    bool hasZero=false;
	    int currSum=0;
	    
	    for(int i=0;i<n;i++){
	       int val = s[i]=='0'? 1:-1;
	       if(s[i]=='0'){
	           hasZero=true;
	       }
	       currSum+=val;
	       maxDiff=max(maxDiff,currSum);
	       
	       if(currSum<0){
	           currSum=0;
	       }
	    }
	    return hasZero?maxDiff:-1;
	}
};