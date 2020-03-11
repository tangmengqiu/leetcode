/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int s= height.size();
        if(s==0) return 0;
        int ret=0;
        int left=0,right=s-1;
        while(left<right){
            int min_hight= min(height[left],height[right]);
            if(min_hight==height[left]){
                left++;
                while(left<right&&height[left]<min_hight){
                    ret+=(min_hight-height[left++]);
                }
            }else{
                right--;
                while(right>left&&height[right]<min_hight){
                    ret+=(min_hight-height[right--]);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

