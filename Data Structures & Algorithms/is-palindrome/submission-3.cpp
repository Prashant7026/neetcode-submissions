class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 65 && s[i] <= 90) {
                s[i] += 32;
            } else if((s[i] < 97 || s[i] > 122) && 
                        (s[i] < 65 || s[i] > 90) && 
                        (s[i] < 48 || s[i] > 57)) {
                s.erase(i, 1);
                i--;
            }
        }

        int i = 0, j = s.size()-1;
        while(i <= j) {
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
