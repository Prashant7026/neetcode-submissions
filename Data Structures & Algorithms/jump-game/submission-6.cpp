class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int maxIndex = 0;
        for(int i = 0; i < len; i++) {
            maxIndex = max(maxIndex, nums[i]+i);
            if(maxIndex >= len-1) return true;
            if(nums[maxIndex] == 0 && i == maxIndex)    return false;
        }

        return true;
    }
};
