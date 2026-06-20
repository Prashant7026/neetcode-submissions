class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, n, ans, "");
        return ans;
    }

    void generate(int open , int close, vector<string> &ans, string str){
        if(open == 0 && close == 0){
            ans.push_back(str);
            return;
        }

        if(open != 0){
            generate(open - 1, close, ans, str + '(');
        }
        if(close > open){
            generate(open, close - 1, ans, str + ')');
        }
        return;
    }
};
