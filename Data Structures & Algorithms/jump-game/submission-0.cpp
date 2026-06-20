class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            int index = i + nums[i];

            if(i == maxJump && index == maxJump && index < nums.size()-1 && nums[index] == 0)    return false;
            
            maxJump = max(maxJump, index);
        }
        return true;
    }
};
