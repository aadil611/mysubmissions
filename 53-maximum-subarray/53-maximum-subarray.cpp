class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_here,max_prev,res=nums[0];
        max_prev=nums[0];
        for(int i=1;i<nums.size();i++){
            max_here = max(max_prev + nums[i],nums[i]);
            res = max(res,max_here);
            max_prev = max_here;
        }
        return res;
    }
};