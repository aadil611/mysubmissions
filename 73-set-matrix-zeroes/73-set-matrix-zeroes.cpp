class Solution {
public:
    void setZero(vector<vector<int>> &matrix,int row,int col,int m,int n){
        for(int i=0;i<m;i++)
            matrix[i][col] = 0;
        for(int i=0;i<n;i++)
            matrix[row][i] = 0;
    }
    
    void setZeroes(vector<vector<int>>& mat) {
        vector<vector<int>> matrix(mat);
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j] == 0 ){
                    setZero(mat,i,j,m,n);
                }
    }
};