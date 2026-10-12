class Solution {
private:
    void combination(int i, vector<int>& nums, int target, vector<int> &temp, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        } 
        
        if(target < 0 || i >= nums.size()) {
            return;
        }

        // Pick
        if(target-nums[i] >= 0) {
            temp.push_back(nums[i]);
            combination(i, nums, target - nums[i], temp, ans);
            temp.pop_back();
        }
        
        // Not pick
        combination(i+1, nums, target, temp, ans);

        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        combination(0, nums, target, temp, ans);

        return ans;
    }
};
