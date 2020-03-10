/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret =INT_MIN;
        if(heights.empty()) return 0;
        for(int i=0;i<heights.size();i++){
            int minHeight = heights[i];
            for(int j=i;j<heights.size();j++){
                if(heights[j]<minHeight) minHeight=heights[j];
                int s= (j-i+1)*minHeight;
                if(s>ret) ret=s;
            }
        }
        return ret;
    }
};
// @lc code=end

