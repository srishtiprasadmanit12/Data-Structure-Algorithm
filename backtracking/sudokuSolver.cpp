/*
1. We have to iterate to every cell, if its empty we try to fill in it with any valid value along.

2. Now if at any point we cant insert valid number etween 1-9 ,it means current state of board is wrong
and we need to backtrack.

3.IMPORTANT: We need to return false, to let parent function know we cannot fill this way.This will serve
as hint to that function that we cannot fill this way and needs to try with next possible number.

4. If a recursive call returns true, we can assume that we found one possible way of filling and
 we simply do an early return.


 VALIDATIN SUDOKU BOARD
 1. We need to check if the number already exists in the row, column or box.
 2. After determining a number for cell ,we check its validity and for that we it should satisfy three 
 conditions.
 3. 
*/

class Solution {
public:
    bool isValid(char c,int row,int col,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            //row-constant,check if this 'c' already exists in row or not
            if(board[row][i]==c)
                return false;
            
            //col constant,check if this 'c' already exists in col or not
            if(board[i][col]==c)
                return false;

            //3x3 block constant,check if this 'c' already exists in that block or not
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        //Iterate over each cell in board
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(c,i,j,board)){
                            board[i][j]=c;
                            
                            //Call recursion further
                            if(solve(board)==true){
                                return true;
                            }
                            else
                                board[i][j]='.';//backtrack to previous state
                            
                        }
                    }                    
                return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);     
    }
};