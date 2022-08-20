class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1=0,i2=0;
        vector<int> res;
        
        while(i1 < m && i2 < n){
            if(nums1[i1] <= nums2[i2])
            {
                res.push_back(nums1[i1]);
                i1++;
            }
            else{
                res.push_back(nums2[i2]);
                i2++;
            }
        }
        for(;i1<m;i1++)
            res.push_back(nums1[i1]);
        for(;i2<n;i2++)
            res.push_back(nums2[i2]);
        
        nums1 = res;
    }
};