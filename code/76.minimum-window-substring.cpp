/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
       string res;
       if(s.length()==0||t.length()==0) return "";
       unordered_map<char,int> s_map,t_map;
       for(auto c : t){
           t_map[c]++;
       }
       int minLen= INT_MAX;
       int letterCounter =0;
       for(int slow=0,fast=0;fast<s.length();fast++){
           char cur_c = s[fast];
           if(t_map.find(cur_c)!=t_map.end()){
               s_map[cur_c]++;
               if(s_map[cur_c]<=t_map[cur_c])
                   letterCounter++;
           }
           if(letterCounter>=t.length()){
               while(t_map.find(s[slow])==t_map.end()||s_map[s[slow]]>t_map[s[slow]]){
                   s_map[s[slow++]]--;
               }
               if(fast-slow+1<minLen){
                   minLen=fast-slow+1;
                   res = s.substr(slow,minLen);
               }
           }
       }
       return res;
    }

};
// @lc code=end

