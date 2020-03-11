/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        vector<string> ans;
        int ret=0;
        placeQueens(n,ans,0,ret);
        return ret;
    }
    void placeQueens(int n,vector<string> &s,int row,int &ret){
        if(row==n){
            ret++;
            return ;
        }
        string tmp(n,'.');
        for(int i=0;i<n;i++){
            tmp[i]='Q';
            s.push_back(tmp);
            if(check(n,row,i,s)){
                placeQueens(n,s,row+1,ret);
            }
            tmp[i]='.';
            s.pop_back();
        }
    }
    bool check(int n,int row,int clm,const vector<string>&s){
       for(int i=0;i<row;i++){
            if(s[i][clm]=='Q')
                return false;
            if((clm-(row-i))>=0&&s[i][clm+i-row]=='Q')
                return false;
            if(clm+row-i<n&&s[i][clm+row-i]=='Q')
                return false;
        }
        return true;
    }
};
// @lc code=end

