class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        if(!isalnum(s[end])) end--;

        while(start <= end){
            while(start < end && !isalnum(s[end])){
                end--;
            }
            while(start < end && !isalnum(s[start])){
                start++;
            }
            if(tolower(s[start]) != tolower(s[end])){
                cout<<s[start]<<" "<<s[end]<<endl;;
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
