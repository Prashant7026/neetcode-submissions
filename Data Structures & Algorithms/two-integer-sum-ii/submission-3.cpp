class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, -1);

        for(int i = 0; i < numbers.size(); i++){
            int start = i + 1, end = numbers.size()-1;
            int find = target - numbers[i];
            while(start <= end){
                int mid = (end + start) / 2;
                if(find == numbers[mid]){
                    ans[0] = i + 1;
                    ans[1] = mid + 1;
                    return ans;
                }else if(find < numbers[mid]){
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }

        return ans;
    }
};
