class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> hm1;
        map<char, int> hm2;
        for(int i = 0; i < s.size(); i++){
            hm1[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            hm2[t[i]]++;
        }

        for(int i = 0; i < max(s.size(), t.size()); i++){
            if(s.size() > t.size()){
                if(hm1[s[i]] != hm2[s[i]])  return false;
            }
            else{
                if(hm1[t[i]] != hm2[t[i]])  return false;
            }
        }

        return true;
    }
};
