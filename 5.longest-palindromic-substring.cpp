/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.85%)
 * Likes:    3824
 * Dislikes: 364
 * Total Accepted:    587.8K
 * Total Submissions: 2.1M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string s_new=insertChar(s);
        const int len=s_new.size();
        vector<int> p(len,0);
        int Mi=0,R=0;
        int maxLen=0,maxPoint=0;
        for(int i=0;i<s_new.size();i++){
            int j=2*Mi-i;
            p[i]=R>i ? min(R-i,p[j]):0;
            int start=i-p[i],end=i+p[i];
            while(start>=1&&end<=len-1&&s_new[start-1] == s_new[end+1]){
                start--;
                end++;
                p[i]++;
            }
            if(i+p[i]>R){
                R=i+p[i];
                Mi=i;
            }
        }
        Mi=max_element(p.begin(),p.end())-p.begin();
        return s.substr((Mi-p[Mi])/2,p[Mi]);
    }

    string insertChar(string s){
        string res="#";
        for(auto ch : s){
            res+=ch;
            res+="#";
        }
        return res;
    }
};

