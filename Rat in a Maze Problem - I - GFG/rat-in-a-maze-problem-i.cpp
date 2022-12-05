//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    bool isPossible(int row,int col,vector<vector<int>> &m,int n,vector<vector<int>> &visited){
        if(row >= 0 && row < n && col >= 0 && col < n && visited[row][col] == 0 && m[row][col] == 1){
            // cout<<"if executed"<<" m : "<<m[row][col]<<endl;
            return true;
        }
            
        return false;
    }
    
    void solve(int row,int col,vector<vector<int>> &m,int n,string &res,vector<string> &ans,
                vector<pair<string,pair<int,int>>> &dirs,vector<vector<int>> &visited){
        if(row == n-1 && col == n-1){
            ans.push_back(res);
            return;
        }
        
        for(auto dir : dirs){
            int drow = dir.second.first;
            int dcol = dir.second.second;
            // cout<<row<<" "<<col<<" "<<drow<<" "<<dcol<<endl;
            if(isPossible(row+drow,col+dcol,m,n,visited)){
                res.append(dir.first);
                visited[row + drow][col + dcol] = 1;
                solve(row+drow,col+dcol,m,n,res,ans,dirs,visited);
                res.pop_back();
                visited[row + drow][col + dcol] = 0;
            }
        }
    }
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<pair<string,pair<int,int>>> dirs{
            { "D",{+1,0} },{ "L",{0,-1} },{ "R",{0,+1}},{ "U",{-1,0} }
        };
        string res = "";
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        if(m[0][0] == 1)
            solve(0,0,m,n,res,ans,dirs,visited);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends