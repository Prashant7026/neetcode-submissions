class Solution {
public:
    unordered_map<int, string> hm;
    string encode(vector<string>& strs) {
        string str = "";
        for(int i = 0; i < strs.size(); i++){
            str += strs[i];
            hm[i] = strs[i];
        }

        return str;
    }

    vector<string> decode(string s) {
        vector<string> str;
        string temp = "";
        for(int i = 0; i < hm.size(); i++){
            str.push_back(hm[i]);
        }
        return str;
    }
};
