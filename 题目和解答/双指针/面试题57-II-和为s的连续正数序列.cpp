class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int left = 1;//左指针（左边界）
        int right = 1;//右指针（右边界）
        int sum = 0;
        while(left<=target/2){//题目要求一个序列至少包含两个数，所以左滑窗到target一半即可。
            if(sum<target){
                sum += right;
                right++;
            }
            else if(sum>target){
                sum -=left;
                left++;
            }
            else{//滑窗内和为target
                vector<int> temp;
                for(int i=left;i<right;i++){
                    temp.push_back(i);
                }
                res.push_back(temp);
                sum -= left;//向右移动左指针，注意和下一句顺序不能反。
                left++;   
            }
        }
        return res;
    }
};
