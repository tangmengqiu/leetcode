/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.19%)
 * Likes:    381
 * Dislikes: 1609
 * Total Accepted:    274.7K
 * Total Submissions: 851.3K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool eixstc =false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                if(!eixstc){
                    len=0;
                }else{
                    return len;
                }
            }else{
                eixstc=true;
                len++;
            }
        }
        return len;
    }
};

