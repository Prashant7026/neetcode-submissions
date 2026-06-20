class Solution {
public:
    int func(vector<int> piles, int bananaPerHr) {
        int result = 0;
        for (int i = 0; i < piles.size(); i++) {
            result += ceil((double)piles[i] / (double)bananaPerHr);
        }

        return result;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int total_hr = func(piles, mid);

            if (total_hr <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
