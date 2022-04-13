class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
        // int mat[n][n];
        int left=0,top=0,right=n-1,bottom=n-1;
        int counter=1;
        while(left<=right && top <= bottom){
            for(int i=left;i<=right;i++)
                mat[top][i]=counter++;
            top++;
            for(int i=top;i<=bottom;i++)
                mat[i][right]=counter++;
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--)
                    mat[bottom][i]=counter++;
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--)
                    mat[i][left]=counter++;
                left++;
            }
        }
        return mat;
    }
};