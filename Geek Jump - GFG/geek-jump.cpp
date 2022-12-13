//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int ind,vector<int> &h,int n,vector<int> &e){
        if(ind == n-1)
            return 0;
        if(e[ind] != -1)
            return e[ind];
            
        int step1 = helper(ind+1,h,n,e) + abs(h[ind + 1] - h[ind]);
        int step2 = INT_MAX;
        if(ind < n - 2)
            step2 = helper(ind+2,h,n,e) + abs(h[ind+2] - h[ind]);
        e[ind] = min(step1,step2);
        return e[ind];
    }
    
    
    int minimumEnergy(vector<int>& h, int n) {
        // memoization //
        // vector<int> energy(n,-1);
        // return helper(0,h,n,energy);
        
        // tabulation //
        if(n <= 1)
            return 0;
        vector<int> dp(n);
        dp[0]=0;
        dp[1]=abs(h[1] - h[0]);
        for(int i=2;i<n;i++){
            dp[i] = min(abs(h[i] - h[i-1] ) + dp[i-1],abs(h[i] - h[i-2] ) + dp[i-2]);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends