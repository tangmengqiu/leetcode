/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][10]={0}, clm[9][10]={0},subBoard[9][10]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int n;
                if (board[i][j]=='.')
                    n=0;
                else
                    n=board[i][j]-'0';
                if(n==0) continue;
                if(++row[i][n]>1)
                    return false;
                if(++clm[j][n]>1)
                    return false;
                if(++subBoard[(i/3)*3+j/3][n]>1)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

