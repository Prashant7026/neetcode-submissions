class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1) return 0;

        sort(nums.begin(), nums.end());
        int count = 1;
        int ans = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                count++;
                ans = max(ans, count);
            }else if(nums[i] > nums[i-1]+1){
                count = 1;
            }
        }

        return ans;
    }
};
