class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int> z = newInterval;

        for(auto i: intervals) {
            if(i[0] > z[1]) {
                ans.push_back(z);
                z = i;
            } else if(i[0] <= z[0] && i[1] >= z[0]) {
                cout<<"hii 1";
                z[0] = min(i[0], z[0]);
                z[1] = max(i[1], z[1]);
            } else if(i[0] >= z[0] && i[1] >= z[1]) {
                cout<<"hii 2";
                z[0] = min(i[0], z[0]);
                z[1] = max(i[1], z[1]);
            } else if(i[0] > z[1]) {
                cout<<"hii 3";
                ans.push_back(z);
                z = i;
            } else if(i[0] > z[0] && i[1] < z[1]) {
                continue;
            } else {
                cout<<"hii 4";
                ans.push_back(i);
            }
        }
        ans.push_back(z);


        return ans;
    }
};
