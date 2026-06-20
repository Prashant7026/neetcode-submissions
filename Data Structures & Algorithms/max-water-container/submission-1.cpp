// For note check leetcode note section

class Solution {
public:
    int maxArea(vector<int>& heights) {
       int start = 0, end = heights.size()-1;
        int ans = INT_MIN;
        while(start < end){
            int temp = min(heights[start], heights[end]) * (end - start);
            ans = max(ans, temp);
            if(heights[start] < heights[end])     start++;
            else    end--;
        }

        return ans; 
    }
};
