/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.33%)
 * Likes:    993
 * Dislikes: 198
 * Total Accepted:    311.3K
 * Total Submissions: 788.5K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int lenA=a.size();
        int lenB=b.size();
        int i=lenA-1,j=lenB-1,flow=0;
        while(i>=0||j>=0||flow==1){
            if(i>=0){
                flow+=a[i--]-'0';
            }
            if(j>=0){
                flow+=b[j--]-'0';
            }
            ans=char(flow%2+'0')+ans;
            flow/=2;
        }
        return ans;
    }
};

