class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        int flag = 0;
        set<int> hs;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                hs.insert(i);
            }
            else{
                flag = 1;
                sum *= nums[i];
            }
        }

        // if(sum == 1)    sum = 0;

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(hs.find(i) != hs.end()){
                if(hs.size() >= 2)  ans.push_back(0);
                else    ans.push_back(flag == 0 ? 0 : sum);
            }else if(hs.size() >= 1){
                ans.push_back(0);
            } else {
                // cout<<"hi";
                int n = nums[i] == 0 ? sum : sum/nums[i];
                ans.push_back(n);
            }
        }

        return ans;
    }
};
