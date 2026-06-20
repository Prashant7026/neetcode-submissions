class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0, j = s1.size()-1;
        unordered_map<char, int> hms1;
        unordered_map<char, int> hms2;
        for(int k = 0; k < s1.size(); k++){
            hms1[s1[k]]++;
        }
        for(int k = i; k <= j; k++){
            hms2[s2[k]]++;
        }
        while(j < s2.size()){
            if(hms2.size() == hms1.size()){
                int flag = 0;
                for(auto k: hms1){
                    if(hms2.find(k.first) == hms2.end() || k.second != hms2[k.first]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)   return true;
            }
            hms2[s2[i]]--;
            if(hms2[s2[i]] == 0)    hms2.erase(s2[i]);
            i++;
            j++;
            if(j < s2.size()){
                hms2[s2[j]]++;
            }
        }

        return false;
    }
};
