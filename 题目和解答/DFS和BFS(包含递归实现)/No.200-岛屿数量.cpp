//BFS实现
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0){
            return 0;
        }
        int cols = grid[0].size();
        queue<pair<int,int>> res;
        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    count++;
                    //queue<pair<int,int>> res;
                    res.push(make_pair(i,j));
                    grid[i][j] = '0';
                    while(!res.empty()){
                        auto [r,c] = res.front();
                        res.pop();
                        if(r-1>=0&&grid[r-1][c]=='1'){
                            res.push(make_pair(r-1,c));
                            grid[r-1][c]='0';
                        }
                        if(r+1<rows&&grid[r+1][c]=='1'){
                            res.push(make_pair(r+1,c));
                            grid[r+1][c]='0';
                        }
                        if(c-1>=0&&grid[r][c-1]=='1'){
                            res.push(make_pair(r,c-1));
                            grid[r][c-1]='0';
                        }
                        if(c+1<cols&&grid[r][c+1]=='1'){
                            res.push(make_pair(r,c+1));
                            grid[r][c+1]='0';
                        }
                    }   
                }
            }
        }
        return count;
    }
};
