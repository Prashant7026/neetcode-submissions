class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long multiply = 1;
        int countOfZero = 0;
        vector<int> ans;

        for(auto i: nums) {
            if(i == 0) {
                countOfZero += 1;
            } else {
                multiply *= i;
            }
        }

        for(auto i: nums) {
            if(i != 0 && countOfZero > 0) {
                ans.push_back(0);
            } else if(i == 0 && countOfZero > 1) {
                ans.push_back(0);
            } else if(i == 0 && countOfZero == 1) {
                ans.push_back(multiply);
            } else {
                ans.push_back(multiply/i);
            }
        }

        return ans;
    }
};
