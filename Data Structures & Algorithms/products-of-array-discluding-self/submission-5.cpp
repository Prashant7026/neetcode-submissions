class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left_product = 1;
        vector<int> ans(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            ans[i] = left_product;
            left_product *= nums[i];
        }

        int right_product = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            ans[i] *= right_product;
            right_product *= nums[i];
        }

        return ans;
    }
};
