class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;// 从根结点到任意结点的选择路径
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,candidates,target);
        return res;
    }

    void dfs(int start, vector<int>& candidates, int target ){
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            //因为candidates排序了，当前的值都比target大，之后的一定也更大，所以直接返回
            if(target - candidates[i] < 0) return;
            path.push_back(candidates[i]);//做选择
            //注意，剪枝的核心在于起点搜索下标为i,根据深度优先树，比i小的下标的值，之前都已经深度遍历多了
            dfs(i,candidates,target-candidates[i]);
            path.pop_back();//撤销选择
        }
    }
};
