class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hm;
        // hs.insert(-1);
        vector<int> ans(2, -1);
        for(int i = 0; i < nums.size(); i++){
            int temp = target - nums[i];
            if(hm.find(temp) != hm.end()){
                ans[0] = hm[temp];
                ans[1] = i;
                return ans;
            }
            hm[nums[i]] = i;
        }

        return ans;
    }
};
