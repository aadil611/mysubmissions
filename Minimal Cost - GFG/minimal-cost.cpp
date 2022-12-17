//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kjump(vector<int> &h,int n,int k,int stair,vector<int> &res){
        if( stair == n-1)
            return 0;
            
        if(res[stair] != -1)
            return res[stair];
            
        res[stair] = INT_MAX;
        for(int j=1; j<=k; j++)
            if(stair + j < n){
                res[stair] = min(res[stair] ,kjump(h,n,k,stair + j,res) + abs(h[stair] - h[stair + j]));
                // cout<<h[stair]<<" "<<h[stair + j]<<endl;
            }
        return res[stair];
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> res(n,-1);
        return kjump(height,n,k,0,res);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends