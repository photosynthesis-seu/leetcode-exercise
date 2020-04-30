//自己的暴力解法：
class Solution {
public:
        set<vector<int>> result;
        vector<int> res;
        int sum;
        //int start = 0;
    vector<vector<int>> threeSum(vector<int>& nums) {
        search(nums,res,result,0);
        auto result1 = vector<vector<int>>(result.begin(),result.end());
        return result1;
    }
    //这种递归相当于写起来简单一些的暴力求解，实际速度一般
            void search(vector<int> nums,vector<int>& res,set<vector<int>>& result,int start){
            sum = accumulate(res.begin(),res.end(),0);
            if(res.size() == 3 && sum == 0 ){
                sort(res.begin(),res.end());
                result.insert(res);
                return;
            }
            if(res.size() == 3){
                return;
            }
            for(int i = start; i< nums.size(); i++){
                //可以保证元素的下标始终比它前面元素的下表大（但无法完全避免重复）
                //例如[-1,0,1]和[0,1,-1]，都是未遍历过的，这种重复难以去除
               //需要使用set
                start = i;
                res.push_back(nums[i]);
                //start = start+1;
                search(nums, res, result, start+1);
                //start = start -1;
                res.pop_back();
            }
        }
};
