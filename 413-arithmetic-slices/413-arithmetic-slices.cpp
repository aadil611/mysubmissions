class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        vector<int> count(nums.size(),0);
        int res;
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                count[i]=count[i-1]+1;
            res+=count[i];
        }
        return res;
    }
};