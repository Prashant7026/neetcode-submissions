class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, -1);
        int start = 0, end = numbers.size()-1;
        while(start < end){
            int temp = numbers[start] + numbers[end];
            if(temp == target){
                ans[0] = start + 1;
                ans[1] = end + 1;
                return ans;
            } else if(temp > target){
                end--;
            } else {
                start++;
            }
        }

        return ans;
    }
};
