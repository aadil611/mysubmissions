class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double qt[101][101]={0.0};
        qt[0][0]=poured;

        for(int i=0;i<query_row;i++){
        	for(int j=0;j<=query_glass;j++){
        		double rem=max(qt[i][j]-1.0,0.0);
        		qt[i+1][j]+=rem/2.0;
        		qt[i+1][j+1]+=rem/2.0;
        	}
        }
        return min(qt[query_row][query_glass],1.0);
    }
};