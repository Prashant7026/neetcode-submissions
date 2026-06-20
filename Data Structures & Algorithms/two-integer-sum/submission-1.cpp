class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;

        for(int i = 0; i < nums.size(); i++) {
            int search = target - nums[i];
            if(hm.find(search) != hm.end()) {
                return {hm[search], i};
            } else {
                hm[nums[i]] = i;
            }
        }

        return {0,0};
    }
};
