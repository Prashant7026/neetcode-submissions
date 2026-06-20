class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())   return 0;
        int i = 0, j = 0;
        unordered_set<int> hs;
        int ans = 1;
        while(j < s.size()){
            if(hs.find(s[j]) == hs.end()){
                hs.insert(s[j]);
                j++;
            } else {
                int temp = hs.size();
                ans = max(temp, ans);
                i = i+1;
                j = i;
                hs.clear();
            }
        }
        int temp = hs.size();
        ans = max(temp, ans);
        return ans;
    }
};
