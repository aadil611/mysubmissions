//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool isPossible(bool graph[101][101],vector<int> &colors,int color,int n,int node){
        for(int i = 0; i < n; i++)
            if(i != node && graph[i][node]==1 && colors[i] == color)
                return false;
        return true;
    }

    bool helper(int node,vector<int> &colors,bool graph[101][101],int m,int n){
        if(n == node)
            return true;
        
        for(int col = 1; col <= m; col++){
            if(isPossible(graph,colors,col,n,node)){
                colors[node] = col;
                if(helper(node+1,colors,graph,m,n))
                    return true;
                colors[node] = 0;
            }
        }
        return false;
    }
    
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        vector<int> colors(n+1,0);
        if(helper(0,colors,graph,m,n))
                    return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends