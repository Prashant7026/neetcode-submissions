class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())   return 0;
        if(s.size() == 1)   return 1;
        int i = 0, j = 0;
        int ans = INT_MIN;
        map<int, int> hm;

        while(j < s.size()){
            hm[s[j]]++;
            if(hm[s[j]] > 1){
                while(hm[s[j]] > 1){
                    hm[s[i]]--;
                    if(hm[s[i]] == 0)   hm.erase(s[i]);
                    i++;
                }
            }
            else {
                int temp = hm.size();
                ans = max(ans, temp);
            }
            j++;
        }

        return ans;
    }
};
