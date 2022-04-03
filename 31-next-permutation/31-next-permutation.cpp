class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return;
        int lastmax=-1;
        for(int i=1;i<n;i++)
            if(nums[i]>nums[i-1])
                lastmax=i;
        
        if(lastmax==-1){
            for(int i=0;i<n/2;i++)
                swap(nums[i],nums[n-1-i]);
            return;
        }
        int index=lastmax;
        for(int i=lastmax;i<n;i++)
            if(nums[i]>nums[lastmax-1] && nums[i]<nums[index])
                index=i;
        
        swap(nums[index],nums[lastmax-1]);
        // prev=lastmax;
        // for(int i=lastmax;i<prev+(n-prev)/2;i++)
        //     swap(nums[i],nums[n-1-i+prev]);
        sort(nums.begin()+lastmax,nums.end());
    }
};