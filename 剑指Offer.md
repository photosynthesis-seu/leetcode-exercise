# 目录
- [No.3 数组中的重复数字](#数组中的重复数字)
- [No.6 从尾到头打印链表](#从尾到头打印链表)//双指针反转链表、辅助栈、巧妙的递归函数
- [No.7 重建二叉树](#重建二叉树)//前序遍历、中序遍历、递归函数DFS
- [No.11 旋转数组的最小数字](#旋转数组的最小数字)//二分查找、双指针算法、特殊情况判断
- [No.12 矩阵中的路径](#阵中的路径)//dfs算法+典型模板、回溯算法、有点动态规划那味
- [No.14 剪绳子I](#剪绳子I)//关注严格的数学原理推导、动态规划
- [No.15 二进制中1的个数](#二进制中1的个数)//n&(n-1),运算符优先级：先算术运算，后移位运算，最后位运算
- [No.16 数值的整数次方](#数值的整数次方)//快速幂法，二分法
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
## 从尾到头打印链表

1.题目
```
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

输入：head = [1,3,2]
输出：[2,3,1]
```
2.反转链表后的实现
```C++
vector<int> reversePrint(ListNode* head) {
        ListNode* cur = NULL;
        ListNode* pre = head;
        while(pre != NULL){
            ListNode* temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        vector<int> res;
        while(cur != NULL){
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }    
```
3.解答汇总**reverse反转法、堆栈法、递归法、改变链表结构法**

+ 关注**递归方法和辅助栈**
```C++
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        //方法1：reverse反转法
        /*
        while(head){
            res.push_back(head->val);
            head = head->next;
        }
        //使用algorithm算法中的reverse反转res
        reverse(res.begin(),res.end());
        return res;
        */

        //方法2：入栈法
        /*
        stack<int> s;
        //入栈
        while(head){
            s.push(head->val);
            head = head->next;
        }
        //出栈
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
        */

        //方法3：递归
        /*
        if(head == nullptr)
            return res;
        res = reversePrint(head->next);
        res.push_back(head->val);
        return res;
        */

        //方法4：改变链表结构
        ListNode *pre = nullptr;
        ListNode *next = head;
        ListNode *cur = head;
        while(cur){
            next = cur->next;//保存当前结点的下一个节点
            cur->next = pre;//当前结点指向前一个节点，反向改变指针
            pre = cur;//更新前一个节点
            cur = next;//更新当前结点
        }
        while(pre){//上一个while循环结束后，pre指向新的链表头
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};
```
## 重建二叉树

1.题目
```
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
```
2.分析
+ 使用一个 Map 存储中序遍历的每个元素及其对应的下标，目的是为了快速获得一个元素在中序遍历中的位置。
+ 实现
```C++
class Solution {
public:
    unordered_map<int,int> dic;//存放中序遍历中节点与下标的对应关系
    TreeNode* head;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            dic[inorder[i]] = i;
        }
        head = PreOrder(preorder,0,0,inorder.size()-1);
        return head;
    }
    //前序遍历递归函数的三个整型参数分别为:
    //子树的根节点在前序遍历的下标，子树在中序遍历中的左边界的下标，子树在中序遍历中的右边界的下标
    //这个子树根据递归算法，可以是左子树也可以是右子树。
    TreeNode* PreOrder(vector<int>& preorder, int root_pre, int left_in, int right_in){
        if(left_in>right_in) return NULL;
        //先使用子树的根节点初始化一个子树
        TreeNode* node = new TreeNode(preorder[root_pre]);
        //获取前序中的根节点在中序中的下标， 即index 左边就是这节点的左子树，index右边就是节点的右子树
        int index = dic[preorder[root_pre]];
        //左子树根节点就是前序遍历中当前根节点的下标加1，这正是前序遍历的性质
        node->left = PreOrder(preorder,root_pre+1,left_in,index-1);
        //右子树根节点在前序遍历中的下标即为:当前根节点下标+左子树节点个数+1
        node->right = PreOrder(preorder,root_pre+index-left_in+1,index+1,right_in);
        return node;
    }
};
```
## 旋转数组的最小数字

**关键在于二分查找时，若边界相等怎么特判！**

1.题目
```
一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

输入：[3,4,5,1,2]
输出：1
```
2.分析
+ 循环二分： 设置 i, j 指针分别指向 numbers 数组左右两端，m = (i + j) // 2 为每次二分的中点（ "//" 代表向下取整除法，因此恒有 i≤m<j ），可分为以下三种情况：
  - 当 numbers[m] > numbers[j]时： m 一定在 左排序数组 中，即旋转点 x 一定在 [m+1,j] 闭区间内，因此执行 i=m+1；
  - 当 numbers[m] < numbers[j] 时： m 一定在 右排序数组 中，即旋转点 x 一定在 [i,m] 闭区间内，因此执行 j=m；
  - 当 numbers[m] == numbers[j] 时： 无法判断 m 在哪个排序数组中，即无法判断旋转点 x 在 [i,m] 还是[m+1,j] 区间中。
+ **解决方案： 执行 j=j−1 缩小判断范围**
+ 返回值： 当 i=j 时跳出二分循环，并返回 numbers[i] 即可。
+ 实现
```C++
int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size()-1;
        int mid;
        while(left<right){
            mid = left + (right-left)/2;
            if(numbers[mid]>numbers[right]){
                left = mid + 1;
            }
            else {
                if(numbers[mid]<numbers[right]){
                    right = mid;
                }
                else{
                    right = right-1;
                }
            }
        }
        return numbers[left];
    }
```
## 矩阵中的路径

1.题目
```
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
```
2.分析
+ 在board中找到一个位置，使得board[i][j] == word[0]，可以作为搜索的入口
+ 由于不能重复进入，因此需要定义一个visit数组，保证每个格子只进入一次
+ 找到一个可行解即返回true。若该次搜索返回false，那么进行寻找下一个可行的入口，进入下一次搜索
+ 直到遍历完整个board，仍没有搜索到目标路径，返回false
3.实现
```C++
vector<vector<int>> direcs{{-1,0},{1,0},{0,-1},{0,1}};//常见的方向向量
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols));//记录是否当前矩阵元素是否访问过，回溯
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
               if(dfs(board,word,visited,0,i,j)){
                   return true;
               }
            }
        }
        return false;
    }
    //DFS算法参数包括矩阵、单词、访问表、当前比对的字符在word的位置、访问的矩阵元素的坐标
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int index, int x, int y){
        //返回条件是word所有字符都能在board找到
        if(index == word.size()-1){
            return board[x][y] == word[index];
        }
        //只有当前矩阵元素等于当前比对的word字符才进一步dfs，否则直接返回false
        if(board[x][y] == word[index]){
            visited[x][y] = true;
            for(auto direc : direcs){
                //一定要声明新的变量new_x，new_y。否则x,y会互相叠加影响，全乱套了
                int new_x = x + direc[0];
                int new_y = y + direc[1];
                //只有没访问过，以及在矩阵内，才会进行dfs递归
                if(new_x>=0&&new_x<board.size()&&new_y>=0&&new_y<board[0].size()&&!visited[new_x][new_y]){
                    if(dfs(board,word,visited,index+1,new_x,new_y)){
                        return true;
                    }
                }
            } 
            visited[x][y] = false;//回溯  
        }
        return false;
    }
```
## 剪绳子I

1.题目
```
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
```
2.分析
+ [严格的数学推导，使用均值不等式与对数化求幂函数极值](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/)
  - 数学推导总体分为两步：1.**当所有绳段长度相等时，乘积最大** 2.**最优的绳段长度为3**
+ 动态规划
  - 可以定义 dp(n) 代表长度为n的绳子分割后的最大可能乘积，那么如果先从 n 中分出来 i 长度的一段，那么 dp(n) = dp(n-i) * dp(i)，然后求最大值即可。
+ 两种方法的实现
  ```C++
  // int cuttingRope(int n) {
    //     if(n<=3) return n-1;
    //     int a = n/3;
    //     int b = n%3;
    //     if(b==0){
    //         return pow(3,a);
    //     }
    //     else if(b==1){
    //         return pow(3,a-1)*4;
    //     }
    //         else{
    //             return pow(3,a)*2;
    //         }
    // }
    int cuttingRope(int n) {
        if(n==2)    return 1;
        if(n==3)    return 2;
        if(n==4)    return 4;
        long res=1;
        while(n>4){//大数越界:当a增大时，最后返回的3^a大小以指数级别增长，可能超出int32甚至int64的取值范围,导致返回值错误。因此考虑循环求余
            res*=3;
            res%=1000000007;
            n-=3;
        }
        return (int)(res*n%1000000007);//这里必须取括号，否则会优先计算res*n的值，报错会超出范围
    }
    int cuttingRope(int n) {
        if(n<=1) return 0;
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++){
            int multi_max=0;
            for(int j=1;j<=i/2;j++){
                multi_max = max(multi_max,dp[i-j]*dp[j]);
            }
            dp[i] = multi_max;
        }
        return dp[n];
    }
  ```
## 二进制中1的个数

1.题目
```
请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
```

2.运算符优先级
+ 基本的优先级需要记住：
  - 指针最优，单目运算优于双目运算，如正负号。
  - 先算术运算，后移位运算，最后位运算。1 << 3 + 2 & 7等价于 (1 << (3 + 2))&7，逻辑运算最后结合。


3.分析
+ 方法一：根据与运算定义，设二进制数字 n ，则有：
  - 若 n&1=0 ，则 n 二进制 最右一位 为 0 ；
  - 若 n&1=1 ，则 n 二进制 最右一位 为 1 。
  - 根据以上特点，考虑以下循环判断 ：
    - 判断 n 最右一位是否为 1 ，根据结果计数。
    - 将 n 右移一位（本题要求把数字 n 看作无符号数，因此使用 无符号右移 操作）
+ 方法二：
  - (n−1) 解析： 二进制数字 n 最右边的 1 变成 0 ，此 1 右边的 0 都变成 1 。
  - n&(n−1) 解析： 二进制数字 n 最右边的 1 变成 0 ，其余不变。
+ 实现：
```C++
// int hammingWeight(uint32_t n) {
    //     int res = 0;
    //     while(n){
    //         res += n&1;
    //         n = n>>1;
    //     }
    //     return res;
    // }
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            res += 1;
            n = n&(n-1);
        }
        return res;
    }
```
## 数值的整数次方
1.题目
```
现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

输入: 2.00000, 10
输出: 1024.00000
```
2.分析
+ [见题目解析](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/mian-shi-ti-16-shu-zhi-de-zheng-shu-ci-fang-kuai-s/)
+ 实现
```C++
double myPow(double x, int n) {
        if(x == 0) return 0;
        long b = n;
        double res = 1.0;
        if(b < 0) {
            x = 1 / x;
            b = -b;
        }
        while(b > 0) {
            if((b & 1) == 1) res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
```
