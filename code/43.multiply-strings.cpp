/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if(nums1=='0'||nums2=='0') return "0";
        int m=nums1.size()-1,n=nums2.size()-1,carry=0;
        string product;
        for (int i=0; i<=m+n || carry; ++i) {
            for (int j=max(0, i-n); j<=min(i, m); ++j)
                carry += (nums1[m-j] - '0') * (nums2[n-i+j] - '0');
            product += carry % 10 + '0';
            carry /= 10;
        }
        reverse(begin(product), end(product));
    }
};
// @lc code=end

