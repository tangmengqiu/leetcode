/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        backTrack(ret,"",n,n);
        return ret;
    }
    void backTrack(vector<string>& ans,string tmp,int left,int right){
        if(left==0&&right==0){
            ans.push_back(tmp);
            return ;
        }
        if(left>right)
            return ;
        if(left>0)
            backTrack(ans,tmp+'(',left-1,right);
        if(right>0)
            backTrack(ans,tmp+')',left,right-1);
    }
};

