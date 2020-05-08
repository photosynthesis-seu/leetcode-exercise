class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int maxSide = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        //dp[i][j]表示以(i,j)为正方形右下角顶点的正方形的最大边长
        vector<vector<int>> dp(rows,vector<int>(cols));
        //将边界中为1的位置dp设为1
        for(int i=0;i<rows;i++){
            if(matrix[i][0] == '1'){
                dp[i][0] = 1;
                maxSide = 1;
            }
        }
        for(int i=0;i<cols;i++){
            if(matrix[0][i] == '1'){
                dp[0][i] = 1;
                maxSide = 1;
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j] == '1'){//为'0'的情况不用写，因为已经dp在初始化时就全为0了。
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;;
                }
                maxSide = max(maxSide,dp[i][j]);
            }
        }
        return maxSide*maxSide;

    }
};
