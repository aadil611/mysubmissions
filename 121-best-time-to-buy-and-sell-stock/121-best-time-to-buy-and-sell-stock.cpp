class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),ans=INT_MIN;
        vector<int> min_here(n),max_here(n);
        
        min_here[0] = prices[0];
        max_here[n-1] = prices[n-1];
        
        for(int i=1;i<n;i++)
            min_here[i] = min(min_here[i-1],prices[i]);
        for(int i=n-2;i>=0;i--)
            max_here[i] = max(max_here[i+1],prices[i]);
        for(int i=0;i<n;i++)
            ans = max(ans,max_here[i] - min_here[i]);
        
        return ans;
    }
};