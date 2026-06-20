class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        // for(int i = 3; i < nums.size(); i++){
        //     if(nums[i] == nums[i-1] && nums[i] == nums[i-2]){
        //         nums.erase(nums.begin() + i);
        //     }
        // }
        int i = 0, j = 1;
        vector<vector<int>> ans;
        set<vector<int>> hs;
        
        for(int i = 0; i < nums.size(); i++) {
            
            int c = -nums[i]-nums[j];
            int start = i + 1, end = nums.size()-1;
            if(i > 0 && nums[i] == nums[i-1])   continue;
            while(start < end){
                vector<int> temp;
                int find = nums[start] + nums[end];
                if(find + nums[i] == 0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    hs.insert(temp);
                    start++;
                    end--;
                } else if(find + nums[i] > 0){
                    end--;
                } else{
                    start++;
                }
            }
        }

        for(auto i : hs){
            ans.push_back(i);
        }

        return ans;
    }
};
