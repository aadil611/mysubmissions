class Solution {
public:
    static int mycmp(vector<int> v1,vector<int> v2){
        return v1[0]<v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        
        sort(intervals.begin(),intervals.end(),mycmp);
        res.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            if(res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else if(res.back()[1] <= intervals[i][1])
                res.back()[1] = intervals[i][1];
        }
        return res;
    }
};