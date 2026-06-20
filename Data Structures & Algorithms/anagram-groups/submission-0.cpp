class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> hm;

        for(int i = 0; i < strs.size(); i++){
            map<char, int> tempHM;
            for(int j = 0; j < strs[i].size(); j++){
                tempHM[strs[i][j]]++;
            }
            hm[tempHM].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto i: hm){
            ans.push_back(i.second);
        }

        return ans;
    }
};
