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
    
    
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> energy(n,-1);
        return helper(0,height,n,energy);
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