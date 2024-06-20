//RECURSION
class Solution {
public:
    int pathSum(vector<vector<int>>& matrix,int r,int c){
        if(r<0||c<0||r>=matrix.size()||c>=matrix[0].size())
                return INT_MAX;

        if (r == matrix.size() - 1)
            return matrix[r][c]; //BASE CASE

        int one = pathSum(matrix,r+1,c-1);
        int two = pathSum(matrix,r+1,c);
        int three = pathSum(matrix,r+1,c+1);

        return  matrix[r][c] + min({one,two,three});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c =  matrix[0].size();
        int ans = INT_MAX;
        for(int i=0;i<c;i++){
            ans = min(ans,pathSum(matrix,0,i));
        }
        return ans;
    }
};

//MEMOISATION
