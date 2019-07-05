/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.11%)
 * Likes:    5753
 * Dislikes: 327
 * Total Accepted:    980.2K
 * Total Submissions: 3.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       /*  map<char,int> show;
        int len=s.size();
        int ret=0;
        int last=0;
        for(int i=0;i<len;i++){
            auto it=show.find(s[i]);
            if(it!=show.end()){
                //find it
               if(last<show[s[i]]+1){
                    last=show[s[i]]+1;
               }
               if(ret<(i-last+1)){
                   ret=i-last+1;
               }
               show[s[i]]=i;
            }else{
                if(ret<(i-last+1)){
                   ret=i-last+1;
               }
                show[s[i]]=i;
            }
        } */
        map<char,int> show;
        int ret=0,start=-1;
        for(int i=0;i!=s.length();i++){
            auto it=show.find(s[i]);
            if (it!=show.end()){
                if(it->second>start)
                    start=it->second;
            }
            show[s[i]]=i;
            ret=max(ret,i-start);
        }

        return ret;


    }
};

