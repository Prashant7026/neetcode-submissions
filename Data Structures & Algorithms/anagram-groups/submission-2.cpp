class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> hm;

        for(auto i: strs) {
            string word = i;
            sort(word.begin(), word.end());
            hm[word].push_back(i);
        }

        for(auto i: hm) {
            ans.push_back(i.second);
        }

        return ans;
    }
};
