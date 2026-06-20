class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> hs;

        for(auto i: nums) {
            hs.insert(i);
        }

        for(auto i: hs) {
            if(hs.find(i-1) == hs.end()) {
                int length = 1;
                int nxtEle = i+1;
                while(hs.find(nxtEle) != hs.end()) {
                    length++;
                    nxtEle++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};
