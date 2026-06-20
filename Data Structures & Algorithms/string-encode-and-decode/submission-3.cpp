class Solution {
public:
    // string key = "!@#$%";
    string key = "!#@!@";
    string encode(vector<string>& strs) {
        string ans = "";
        for(auto i: strs) {
            ans += i;
            ans += key;
        }
        return ans;
    }

    vector<string> decode(string s) {
        string str = "";
        vector<string> ans;
        for(int i = 0; i < s.size(); i++) {
            if(i < s.size() && s[i] == key[0] && s[i+key.size()-1] == key[key.size()-1]) {
                ans.push_back(str);
                i += 4;
                str = "";
            } else {
                str += s[i];
            }
        }

        return ans;
    }
};
