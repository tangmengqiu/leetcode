/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (51.74%)
 * Likes:    650
 * Dislikes: 2024
 * Total Accepted:    253.1K
 * Total Submissions: 488.8K
 * Testcase Example:  '3'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: "III"
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "IV"
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: "IX"
 * 
 * Example 4:
 * 
 * 
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
class Solution {
public:
    string intToRoman(int num) {
        std::string ans;
        for(int i=0;i<num/1000;i++){
            ans+="M";
        }
        num=num%1000;
        //num <1000

        //num>=900
        if(num/900==1){
            ans+="CM";
            num=num%900;
        }
        //num>=500
        if(num>=500){
            ans+="D";
            num-=500;
        }

        //400<=num<500
        if(num/400==1){
            ans+="CD";
            num-=400;
        }
        //100<=num<400
        for(int i=0;i<num/100;i++){
            ans+="C";
        }
        num=num%100;
        //num<100

        //num>=90
        if(num/90==1){
            ans+="XC";
            num=num%90;
        }
        //50<=num<90
        if(num>=50){
            ans+="L";
            num-=50;
        }
        //10<=num<50

        //40<=num<50
        if(num/40==1){
            ans+="XL";
            num-=40;
        }
        // 10<=num<40
        for(int i=0;i<num/10;i++){
            ans+="X";
        }
        num=num%10;

        //num==9
        if(num==9){
            ans+="IX";
            return ans;
        }
        //5<=num<9
        if(5<=num){
            ans+="V";
            for(int i=0;i<num-5;i++){
                ans+="I";
            }
            return ans;
        }
        //num==4
        if(num==4){
            ans+="IV";
            return ans;
        }
        //num<4
        for(int i=0;i<num;i++){
            ans+="I";
        }
        return ans;
    }
};

