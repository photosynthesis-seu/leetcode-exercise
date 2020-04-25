class Solution {
public:
    vector<vector<int>> res;
    // 路径：记录在 track 中
    // 选择列表：nums 中不存在于 track 的那些元素
    // 结束条件：nums 中的元素全都在 track 中出现
    void backtrack(vector<int>& nums, vector<int>& track){
        // 所有数都填完了
        if (track.size() == nums.size()) {
            res.emplace_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            vector<int>::iterator itr = find(track.begin(),track.end(),nums[i]); 
            if(itr != track.end()){
                continue;
            }
            track.emplace_back(nums[i]);
            backtrack(nums,track);
            track.pop_back();  
        }
    }
    /* 主函数，输入一组不重复的数字，返回它们的全排列 */
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return {};
	    if (nums.size() == 1) return { {nums[0]} };
        vector<int> track;
        backtrack(nums,track);
        return res;
    }
};
