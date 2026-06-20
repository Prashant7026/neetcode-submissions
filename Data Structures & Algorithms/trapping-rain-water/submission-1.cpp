class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lMax(height.size(), 0);
        vector<int> rMax(height.size(), 0);
        
        for(int i = 1; i < height.size(); i++) {
            int maxEle = max(height[i-1], lMax[i-1]);
            lMax[i] = maxEle;
        }

        for(int i = height.size()-2; i >= 0; i--) {
            int maxEle = max(height[i+1], rMax[i+1]);
            rMax[i] = maxEle;
        }

        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            int filled = min(lMax[i], rMax[i]) - height[i];
            if(filled > 0) {
                ans += filled;
            }
        }

        return ans;
    }
};
