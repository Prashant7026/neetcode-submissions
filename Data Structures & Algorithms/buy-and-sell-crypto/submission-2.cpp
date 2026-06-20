class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1;
        int ans = 0;
        while(j < prices.size()) {
            int profit = prices[j] - prices[i];
            if(profit < 0){
                i++;
                if(i == j)  j++;
            } else if(profit > ans) {
                ans = profit;
                j++;
            } else {
                j++;
            }
        }

        return ans;
    }
};
