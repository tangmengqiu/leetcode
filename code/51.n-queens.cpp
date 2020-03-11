/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> ans;
        backTrack(n,ret,ans,0);
        return ret;
    }
    void backTrack(int n,vector<vector<string>> &ret,vector<string> &pre,int row){
        string s(n,'.');
        for(int clm=0;clm<n;clm++){
            s[clm]='Q';
            vector<string> bk=pre;
            pre.push_back(s);
            if(check(n,row,clm,pre)){
                if(row==n-1){
                    ret.push_back(pre);
                    return;
                }else{
                    backTrack(n,ret,pre,row+1);
                }    
            }
            s[clm]='.';
            pre = bk ;
        }  
    }
    bool check(int n,int row,int clm,vector<string> tmp){
        //check clm
        for(int i=0;i<row;i++){
            if(tmp[i][clm]=='Q')
                return false;
            if((clm-(row-i))>=0&&tmp[i][clm+i-row]=='Q')
                return false;
            if(clm+row-i<n&&tmp[i][clm+row-i]=='Q')
                return false;
        }
        return true;

        //check left diagonal

        //check right diagonal
    }
};
// @lc code=end

