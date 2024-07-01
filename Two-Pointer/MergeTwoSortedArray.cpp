//Merge two sorted arrays in ascending order
// BRUTE FORCE APPROACH : Time complexity -> (N+M)log(N+M)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //merge both array
    for(int i=0,j=m;i<n;i++){
        nums1[j]=nums2[i];
        j++;
    }
    //use stl sort to sort the function
    sort(nums1.begin(),nums1.end());
}
//OPTIMISED APPROACH : time complexity -> O(N+M)
//Running three pointer all from end of arrays

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          int k = n+m-1;
          int i=m-1;
          int j=n-1;
          while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;k--;
            }
            else{
                nums1[k]=nums2[j];
                j--;k--;
            }
          }
        while(j>=0){
            nums1[k]=nums2[j];
            j--;k--;
        }
    
        }
    };
    /*
    nums1 = [1,2,2,3,5,6], m = 3, Nums2 = [2,5,6], n = 3
             i k                      j
    */