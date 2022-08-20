class Solution {
public:
    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     for(int i=0;i<n;i++)
    //         for(int j=i;j<n;j++)
    //             swap(matrix[i][j],matrix[j][i]);
    //     for(int col=0;col<n/2;col++)
    //         for(int row=0;row<n;row++)
    //             swap(matrix[row][col],matrix[row][n-col-1]);
    // }
    
    // if not asked for in-place 
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> tmp(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                tmp[j][n-i-1] = matrix[i][j];
        matrix = tmp;
    }
};

