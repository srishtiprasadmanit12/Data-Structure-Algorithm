//BRUTE FORCE APPROACH 
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int n = height.size();
            int ans = INT_MIN;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int l = min(height[i],height[j]);
                    int b = abs(j-i);
                    ans = max(ans,l*b);
                }
            }
            return ans;
    
            
        }
    };
    
//OPTIMISED APPROACH - TWO POINTER APPROACH
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int n = height.size();
            int ans = INT_MIN;
            int left = 0,right=n-1;
            while(left<right){
             int area = (right-left)*(min(height[left],height[right])); 
             ans = max(ans,area);
             if(height[left]>height[right]){
                right--;
             }
             else{
                left++;
             }
            }
            return ans;       
        }
    };
    
    
    /*               1 2 3 4 5 6 7 8 9 
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    b=1 ,l=1 Area=1
    
    */