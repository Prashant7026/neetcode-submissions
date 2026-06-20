class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> hm1;

        for(int i = 0; i < s.size(); i++) {
            hm1[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++) {
            if(hm1[t[i]] == 0){
                return false;
            }
            if(hm1.find(t[i]) != hm1.end()) {
                hm1[t[i]]--;
            } else {
                return false;
            }
        }

        return true;
    }
};
