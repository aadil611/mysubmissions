class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),breakpoint;
        for(breakpoint = n-2; breakpoint >= 0; breakpoint--)
            if(nums[breakpoint] < nums[breakpoint + 1])
                break;
       
        if(breakpoint < 0)
            reverse(nums.begin(),nums.end());
        else{
            int lastgreater;
            for(lastgreater = n-1; lastgreater > breakpoint;lastgreater--)
                if(nums[lastgreater] > nums[breakpoint])
                    break;
            swap(nums[breakpoint],nums[lastgreater]);
            reverse(nums.begin() + breakpoint + 1,nums.end());
        }
    }
};