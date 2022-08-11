class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        if(numRows == 1)
            return pascal;
        pascal.push_back({1,1});
        for(int i=0;i<numRows-2;i++){
            vector<int> prevRow = pascal.back();
            vector<int> curRow;
            int prev=0;
            for(int x:prevRow){
                curRow.push_back(x+prev);
                prev=x;
            }
                
            curRow.push_back(prevRow.back());
            pascal.push_back(curRow);
        }
        return pascal;
    }
};