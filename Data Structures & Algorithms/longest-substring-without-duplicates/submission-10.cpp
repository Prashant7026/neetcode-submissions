class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> hm;
        int ans = 0;
        while(j < s.size()) {
            hm[s[j]]++;
            if(hm[s[j]] > 1) {
                while(hm[s[j]] > 1) {
                    hm[s[i]]--;
                    if(hm[s[i]] == 0)   hm.erase(s[i]);
                    i++;
                }
            } else {
                ans = max(ans, (int)hm.size());
            }

            j++;
        }

        return ans;
    }
};
