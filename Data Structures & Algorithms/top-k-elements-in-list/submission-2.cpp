class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        set<int> hs;
        for(int i = 0; i < nums.size(); i++){
            hm[nums[i]]++;
            hs.insert(nums[i]);
        }

        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(auto i: hm){
            pq.push({i.second, i.first});
        }

        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
