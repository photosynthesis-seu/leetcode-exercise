class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        // 特判
        if (nums[len - 1] < target) {
            return len;
        }
        int res;
        res = BinarySearch(nums,target,0,len-1);
        return res;

    }
    int BinarySearch(vector<int>& nums,int target,int left,int right){
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid]<target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};
