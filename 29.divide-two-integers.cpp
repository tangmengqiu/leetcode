/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool f=true;
        if(dividend==0) return 0;
        double a=log(fabs(dividend));
        double b=log(fabs(divisor));
        long long ans=double(exp(a-b));
        if((dividend<0)^(divisor<0)) ans=-ans;
        if(ans>INT_MAX) return INT_MAX;
        return ans;
    }
};
// @lc code=end

