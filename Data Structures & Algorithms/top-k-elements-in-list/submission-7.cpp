class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> mxQueue;
        vector<int> ans;
        unordered_map<int, int> hm;

        for(auto i: nums) {
            hm[i]++;
        }
        
        for(auto i: hm) {
            mxQueue.push({i.second, i.first});
        }

        while(!mxQueue.empty() && k > 0) {
            ans.push_back(mxQueue.top().second);
            mxQueue.pop();
            k--;
        }

        return ans;
    }
};
