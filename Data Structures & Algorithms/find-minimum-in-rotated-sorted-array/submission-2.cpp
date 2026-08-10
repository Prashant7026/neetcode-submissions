class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        int first = nums[0];
        int ans = INT_MAX;

        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] > nums[nums.size() - 1]) {
                ans = min(ans, nums[mid]);
                start = mid + 1;
            } else if(mid > 0 && nums[mid] > nums[mid - 1]) {
                ans = min(ans, nums[mid]);
                end = mid - 1;
            } else {
                return nums[mid];
            }
        }

        return ans;
    }
};
