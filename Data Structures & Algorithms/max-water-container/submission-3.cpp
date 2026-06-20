class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int ans = 0;
        while(i < j) {
            int temp = min(heights[i], heights[j]) * (j - i);
            ans = max(ans, temp);
            if(heights[i] < heights[j])     i++;
            else    j--;
        }

        return ans;
    }
};
