class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;
        vector<int> res;
        for(auto x : nums)
            m[x]++;
        for(auto x : m)
            pq.push({x.second,x.first});
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};