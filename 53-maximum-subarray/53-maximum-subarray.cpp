class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_here[nums.size()],res=nums[0];
        max_here[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            max_here[i] = max(max_here[i-1] + nums[i],nums[i]);
            res = max(res,max_here[i]);
        }
        return res;
    }
};