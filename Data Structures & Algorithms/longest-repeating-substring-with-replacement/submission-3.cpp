class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, maxFreq = INT_MIN;
        unordered_map<int, int> hm;
        int ans = INT_MIN;

        while(j < s.size()){
            hm[s[j]]++;
            maxFreq = max(maxFreq, hm[s[j]]);
            int valid = (j - i + 1) - maxFreq;
            if(valid <= k)  ans = max(ans, j - i + 1);
            else{
                hm[s[j--]]--;
                maxFreq = max(maxFreq, hm[s[j]]);
                hm[s[i]]--;
                maxFreq = max(maxFreq, hm[s[i]]);
                i++;
            }
            j++;
        }

        return ans;
    }
};
