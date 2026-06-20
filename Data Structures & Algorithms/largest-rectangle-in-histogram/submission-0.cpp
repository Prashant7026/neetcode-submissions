class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftSmaller(heights.size(), -1);
        stack<int> st1;
        for(int i = 0; i < heights.size(); i++){
            if(!st1.empty()){
                while(!st1.empty() && heights[i] <= heights[st1.top()]){
                    st1.pop();
                }
                if(!st1.empty()){
                    leftSmaller[i] = st1.top();
                }
            }
            st1.push(i);
        }

        vector<int> rightSmaller(heights.size(), -1);
        stack<int> st2;
        for(int i = heights.size()-1; i >= 0; i--){
            if(!st2.empty()){
                while(!st2.empty() && heights[i] <= heights[st2.top()]){
                    st2.pop();
                }
                if(!st2.empty()){
                    rightSmaller[i] = st2.top();
                }
            }
            st2.push(i);
        }

        int ans = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            int a, b;
            if(leftSmaller[i] == -1){
                a = i;
            } else {
                a = i - leftSmaller[i] - 1;
            }
            if(rightSmaller[i] == -1){
                b = heights.size() - i;
            } else {
                b = rightSmaller[i] - i;
            }
            ans = max(ans, heights[i] * (a+b));
        }

        return ans;
    }
};
