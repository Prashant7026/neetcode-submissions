class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> hs;

        for(auto i: nums) {
            hs.insert(i);
        }

        for(auto i: nums) {
            vector<int> check;
            check.push_back(i-1);
            int ele = i-1;
            while(hs.find(ele) != hs.end()) {
                check.push_back(ele);
                ele--;
            }
            ans = max(ans, (int)check.size());
        }

        return ans;
    }
};
