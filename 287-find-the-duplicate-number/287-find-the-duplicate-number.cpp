class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res=1,n=nums.size();
        set<int> s;
        s.insert(nums[0]);
        for(int i=1;i<n;i++){
            if( s.find(nums[i]) != s.end() ){
                res = nums[i];
                break;
            }
            s.insert(nums[i]);
        }
        return res;
    }
};