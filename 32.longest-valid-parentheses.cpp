/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int ret=0;
        std::stack<int> match;
        int start=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                match.push(i);
            }else{
                if(match.empty()){
                    start=i+1;
                }else{
                    int top=match.top();
                    match.pop();
                    if(match.empty()){
                        ret=max(ret,i-start+1);
                    }else{
                        ret=max(ret,i-match.top());
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end

