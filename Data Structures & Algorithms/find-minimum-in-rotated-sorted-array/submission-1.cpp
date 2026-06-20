class Solution {
public:
    int findMin(vector<int> &nums) {
        int a = nums[0];
        if(nums.size() == 1)    return nums[0];
        if(a < nums[nums.size() - 1])   return a;

        int start = 0, end = nums.size()-1;
        int ans = INT_MAX;
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] >= a){
                start = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                end = mid - 1;
            }
        }
        return ans;
    }
};
