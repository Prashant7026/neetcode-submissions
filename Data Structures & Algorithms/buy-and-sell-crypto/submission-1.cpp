class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int ans = 0;
        while(right < prices.size()){
            if(prices[left] < prices[right]){
                int temp = prices[right] - prices[left];
                ans = max(ans, temp);
            } else {
                left = right;
            }
            right++;
        }

        return ans;
    }
};
