class Solution {
public:
    static bool sortFunc(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortFunc);

        int lastEndingTime = intervals[0][1];
        int ans = 0;

        for(int i = 1; i < intervals.size(); i++) {
            if(lastEndingTime > intervals[i][0]) {
                ans++;
            } else {
                lastEndingTime = intervals[i][1];
            }
        }

        return ans;
    }
};
