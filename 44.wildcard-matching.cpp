/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int s_len =s.length(),p_len=p.length();
        int i=0,j=0,asterisk =-1,match ;
        while(i<s_len){
            if(j<p_len&&p[j]=='*'){
                match=i;
                asterisk =j++;
            }else if(j<p_len&&(s[i]==p[j]||p[j]=='?')){
                i++;
                j++;
            }else if(asterisk>=0){
                i=++match;
                j=asterisk+1;
            }else return false;
        }
        while(j<p_len&&p[j]=='*') j++;
        return j==p_len;
    }
    
};
// @lc code=end
