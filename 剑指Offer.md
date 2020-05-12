# 目录
- [No.3 数组中的重复数字](#数组中的重复数字)

# 题目

## 数组中的重复数字

1.题目
```
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
```
2.哈希表低级做法
```C++
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> res;
        for(auto num : nums){
            if(res.count(num)){
                return num;
            }
            res.emplace(num);
        }
        return -1;
    }
```
3.交换法
+ 如果没有重复数字，那么正常排序后，数字i应该在下标为i的位置，所以思路是重头扫描数组，遇到下标为i的数字如果不是i的话，（假设为m),那么我们就拿与下标m的数字交换。在交换过程中，如果有重复的数字发生，那么终止返回ture。
+ 需要注意，这种算法成立的前提是**长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内**
+ 实现
```C++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i] != i){//在原本位置的nums[i]一定要跳过，因为会影响判断是否出现重复数字
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                int temp = nums[i];
                //注意这里不能写nums[i] = nums[nums[i]]，否则会无限循环
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;    
    }
};
```

