class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            maxJump = max(maxJump, nums[i] + i);
            if(maxJump == i && nums[i] == 0 && i < nums.size() - 1)    return false;
        }

        return true;
    }
};
