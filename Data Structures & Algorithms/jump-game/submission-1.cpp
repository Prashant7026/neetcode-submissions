class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxJump)    return false;
            
            int index = i + nums[i];
            maxJump = max(maxJump, index);
        }
        return true;
    }
};
