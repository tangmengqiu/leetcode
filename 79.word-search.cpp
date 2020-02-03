/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backTrack(board,word,i,j))
                    return true;
            }
        }
        return false;
    }
    bool backTrack(vector<vector<char>>& board, string word, int row,int clm){
        if(!word.size()) return true;
        if(row<0||row>=board.size()||clm<0||clm>=board[0].size())
            return false;
        char c = board[row][clm];
        if(c!=word[0]) return false;
        board[row][clm]='*';
        word=word.substr(1);
        if(backTrack(board,word,row-1,clm)||backTrack(board,word,row+1,clm)||backTrack(board,word,row,clm-1)||backTrack(board,word,row,clm+1))
            return true;
        board[row][clm]=c;
        return false;
    }
};
// @lc code=end

