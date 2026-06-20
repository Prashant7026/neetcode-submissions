class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxElement = INT_MIN;
        for(auto i: nums) {
            if(i > maxElement)  maxElement = i;
        }

        int sum = 0;
        int ans = 0;
        for(auto i: nums) {
            if(sum < 0) {
                sum = 0;
            }
            sum += i;
            ans = max(ans, sum);
        }

        cout<<ans<<maxElement;
        if(ans == 0 && ans != maxElement)   return maxElement;

        return ans;
    }
};
