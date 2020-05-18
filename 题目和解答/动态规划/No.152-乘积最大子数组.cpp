class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> max_dp(nums.size());
        vector<int> min_dp(nums.size());
        int res;
        max_dp[0] = nums[0];
        min_dp[0] = nums[0];
        res = max_dp[0];
        for(int i=1;i<nums.size();i++){
            max_dp[i] = max(max(max_dp[i-1]*nums[i],nums[i]),min_dp[i-1]*nums[i]);
            min_dp[i] = min(min(min_dp[i-1]*nums[i],nums[i]),max_dp[i-1]*nums[i]);
            res = max(res,max_dp[i]);
        }

        return res;
    }
};
