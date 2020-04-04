class Solution {
public:
    int minDistance(string word1, string word2) {
         int m = word1.size();
        int n = word2.size();
        vector<vector<int>> cost(m+1, vector<int>(n+1,0));

        // 必须具有0->0 ，消耗为0，这里索引是从1开始的。
        // word1:1..m  ; word2:1..n
        for(int i=0;i<=m;i++){
            cost[i][0] = i;// word2是0，那么word1中的i个要全部删除
        }
        for(int j=0;j<=n;j++){
            cost[0][j] = j;// word1是0，那么word1增加每一个word2的字符个数j
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int min_ = 1999;
                if(word1[i-1] == word2[j-1]){
                    // 因为i和j是从1开始计数，对于word索引要-1
                    min_ = cost[i-1][j-1];
                }
                min_ = min(min_, cost[i-1][j-1]+1);// i替换j
                min_ = min(min_, cost[i-1][j]+1);// 删除i
                cost[i][j] = min(min_, cost[i][j-1]+1);// 增加
            }
        }
        return cost[m][n];
    }
};
