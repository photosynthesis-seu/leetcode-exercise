class Solution {
    public:
        int superEggDrop(int K, int N) {
        vector<vector<int>> middleResults(K+1,vector<int>(N+1,0));
        for (int i = 1; i <= N; i++) {
            middleResults[1][i] = i; // only one egg
            middleResults[0][i] = 0; // no egg
        }
        for (int i = 1; i <= K; i++) {
            middleResults[i][0] = 0; // zero floor
        }

        for (int k = 2; k <= K; k++) { // start from two egg
            for (int n = 1; n <= N; n++) {
                int tMinDrop = N * N;
                for (int x = 1; x <= n; x++) {
                    tMinDrop = min(tMinDrop, 1 + max(middleResults[k - 1][x - 1], middleResults[k][n - x]));
                }
                middleResults[k][n] = tMinDrop;
            }
        }

        return middleResults[K][N];
    }
};
