class Solution {
public:
    int sizeOfMap(unordered_map<char, int> &hm) {
        int size = 0;
        for(auto i: hm) {
            if(i.second > 0)    size++;
        }

        return size;
    }

    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> hm;
        int ans = 0;
        while(j < s.size()) {
            hm[s[j]]++;
            if(hm[s[j]] > 1) {
                while(hm[s[j]] > 1) {
                    hm[s[i++]]--;
                }
            } else {
                ans = max(ans, sizeOfMap(hm));
            }

            j++;
        }

        return ans;
    }
};
