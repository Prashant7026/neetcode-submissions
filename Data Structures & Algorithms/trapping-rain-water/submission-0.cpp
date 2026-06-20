class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> LMax(height.size(), -1);
        vector<int> RMax(height.size(), -1);

        for(int i = 1; i < height.size(); i++){
            LMax[i] = max(LMax[i-1], height[i-1]);
        }

        for(int i = height.size()-2; i >= 0; i--){
            RMax[i] = max(RMax[i+1], height[i+1]);
        }

        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            int temp = min(LMax[i], RMax[i]) - height[i];
            if(temp > 0){
                ans += temp;
            }
        }

        return ans;
    }
};
