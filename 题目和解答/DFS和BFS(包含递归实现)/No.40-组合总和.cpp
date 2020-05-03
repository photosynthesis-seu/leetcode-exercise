class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        if(candidates.size()==0) return {};
        dfs(candidates,target,0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int start){
        if(target == 0){
            res.push_back(path);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(target-candidates[i]<0){
                return;
            } 
            if(i>start&&candidates[i] == candidates[i-1]) continue;//仔细思考，关键的剪枝判断！
            path.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i+1);
            path.pop_back();
        }
    }
};
