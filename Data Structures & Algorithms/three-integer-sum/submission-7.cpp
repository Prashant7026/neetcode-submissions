class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            int start = i+1, end = nums.size()-1;
            if(i > 0 && nums[i] == nums[i-1])   continue;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == 0) {
                    vector<int> temp;
                    temp.insert(temp.end(), {nums[i], nums[start], nums[end]});
                    ans.push_back(temp);
                    start++;
                    end--;
                    while(start < end && nums[start] == nums[start-1]){
                        start++;
                    }
                    while(start < end && nums[end] == nums[end+1]){
                        end--;
                    }
                }
                else if(sum < 0)    start++;
                else    end--;
            }
        }

        return ans;
    }
};
