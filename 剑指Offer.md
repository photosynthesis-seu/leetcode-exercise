# 目录
- [No.3 数组中的重复数字](#数组中的重复数字)
- [No.6 从尾到头打印链表](#从尾到头打印链表)//双指针反转链表、辅助栈、巧妙的递归函数
- [No.7 重建二叉树](#重建二叉树)//前序遍历、中序遍历、递归函数DFS
- [No.11 旋转数组的最小数字](#旋转数组的最小数字)//二分查找、双指针算法、特殊情况判断
- [No.12 矩阵中的路径](#阵中的路径)//dfs算法+典型模板、回溯算法、有点动态规划那味
- [No.14 剪绳子I](#剪绳子I)//关注严格的数学原理推导、动态规划
- [No.15 二进制中1的个数](#二进制中1的个数)//n&(n-1),运算符优先级：先算术运算，后移位运算，最后位运算
- [No.16 数值的整数次方](#数值的整数次方)//快速幂法，二分法
- [No.17 打印从1到最大的n位数](#打印从1到最大的n位数)//pow()函数、大数解法
- [No.18 删除链表的节点](#删除链表的节点)//注意考虑所有情况
- [No.19 正则表达式匹配](#正则表达式匹配)//比较复杂的动态规划
- [No.20 表示数值的字符串](#表示数值的字符串)//几个神奇的函数find_first_not_of...,根据e划分指数和底数
- [No.21 调整数组顺序使奇数位于偶数前面](#调整数组顺序使奇数位于偶数前面) //典型的首尾双指针、快慢指针题目，一定要会！！
- [No.22 链表中倒数第k个节点](#链表中倒数第k个节点)//快慢双指针
- [No.24 反转链表](#反转链表)//常规操作，反转链表
- [No.25 合并两个排序的链表](#合并两个排序的链表)//关注哨兵节点
- [No.26 树的子结构](#树的子结构)//巧妙的使用两种递归（就不使用回溯算法了）
- [No.27 二叉树的镜像](#二叉树的镜像)//递归算法
- [No.29 顺时针打印矩阵](#顺时针打印矩阵)//需要非常细致的分类讨论
- [No.30 包含min函数的栈](#包含min函数的栈)//双栈，注意使用辅助栈
- [No.31 栈的压入、弹出序列](#栈的压入、弹出序列)//模拟栈的压入和弹出，那个while判断是核心！！！
- [No.32-I 从上到下打印链表](#从上到下打印链表)//广度优先、队列
- [No.35 复杂链表的复制](#复杂链表的复制)//深拷贝与浅拷贝的区别
- [No.40 最小的k个数](#最小的k个数)//大根堆、快速排序与归并排序算法的排坑（注意归并排序的返回条件）

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
	//PS：考虑左子树不存在，右子树存在的情况，此时left_in>right_in,所以一定会返回null
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
+ n&1 （与操作）： 判断 n 二进制最右一位是否为 1 ；
+ n>>1 （移位操作）： n 右移一位（可理解为删除最后一位）。
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
## 打印从1到最大的n位数
1.题目
```
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
```
2.分析
+ pow函数实现
```C++
class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> res;
		if (n == 0) return res;
		//打印到数组中
		for (int i=1,max=pow(10,n);i<max;i++)
		{
			res.push_back(i);
		}
		return res;
	}
}; 
```
+ 大数的string解法
```C++
class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		//创建一个能容纳最大值的字符数组
		string number(n, '0');
		//初始全部设置为0
		while (!Increment(number))
		{
			saveNumber(number);
		}
		return res;
	}
	bool Increment(string& number) {
		//注意要使用引用传递，否则无法修改number
		bool isOverflow = false;//检测是否越界
		int nTakeOver = 0;//存储进位
		int nLength = number.size();
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				//如果是第一位，进位
			{
				nSum++;
			}
			if (nSum >= 10)//有进位
			{
				if (i == 0)
					//如果是最高位有进位，说明超过了给定得到最大值，越界
				{
					isOverflow = true;
				}
				else
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//对第i位进行设置
				}
			}
			else//没有进位
				//设置第i位数字
				//并直接跳出循环
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void saveNumber(string number)
		//由于此处输出，不需要修改number，因此不需要加引用
	{
		string s = "";
		bool isBegin0 = true;
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			if (!isBegin0)
			{
				s += *it;
			}
			it++;
		}
		int num = stoi(s);
		res.push_back(num);
	}
};
```

## 删除链表的节点

1.题目
```
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
```
2.分析
+ 实现
```C++
 ListNode* deleteNode(ListNode* head, int val) {
        ListNode* res = head;
        if (res->val == val){
            return res->next;
        }
        while(res->next){
            if(res->next->val == val){
                if(res->next->next){
                    res->next = res->next->next;
                }
                else{
                    res->next = NULL;
                    break;
                }
            }
            res = res->next;
        }
        return head;
    }
```
## 正则表达式匹配
1.题目
```
请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
```
2.分析
+ [见这篇解析](https://leetcode-cn.com/problems/regular-expression-matching/solution/ji-yu-guan-fang-ti-jie-gen-xiang-xi-de-jiang-jie-b/)
+ 实现
```C++
class Solution {
public:
    //记忆表
    vector<vector<int>>memo;
    bool isMatch(string s, string p) {
        // 大小+1的目的是因为memo有边界限制，在递归出口是只判断了pi，但没有限制si
        memo = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        return helper(0, 0, s, p);
    }
    bool helper(int si, int pi, string s, string p) {
        //递归出口
        //当si==s.size() 且 pi < p.size()时 可能p中还有“*”字符 可以令前面的字符出现0次以匹配s
        if(pi == p.size()) {
            return si == s.size();
        }
        //如果判断过了直接返回存储的结果
        if(memo[si][pi] != -1) { 
            return memo[si][pi]; 
        } 
        bool res = false; //整个结果是否匹配
        bool cur_match = false; //当前字符是否匹配
        if(si < s.size()) {
            if(s[si] == p[pi] || p[pi] == '.') {
                cur_match = true;
            }
        }
        //判断下一个字符是否'*'
        if((pi + 1) < p.size() && p[pi + 1] == '*') {
            // 考虑只需两种情况：
            // 情况1：当前字符出现0次：跳过pattern中的当前字符和下一个"*"==>helper(si, pi + 2, s, p)
            // 情况2：当前字符出现1次：当前是否匹配 && 将字符s向后移动一位是否匹配==>cur_match && helper(si + 1, pi, s, p)
            res = helper(si, pi + 2, s, p) || (cur_match && helper(si + 1, pi, s, p));
        } else {
            res = cur_match && helper(si + 1, pi + 1, s, p); //下一个不是"*"正常向后匹配就好
        }
        memo[si][pi] = res;
        return res;
    }
};
```
## 调整数组顺序使奇数位于偶数前面
1.题目
```
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
```
2.自己的方法(**简单的insert实现，注意vector中insert的使用**)
```C++
vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        int left = 0;
        for(auto num : nums){
            if(num%2 == 1){
                res.insert(res.begin()+left,num);
                left++;
            }
            else{
                res.push_back(num);
            }
        }
        return res;
    }
```
3.首尾双指针实现
+ 定义头指针 left ，尾指针 right
  - left 一直往右移，直到它指向的值为偶数
  - right 一直往左移， 直到它指向的值为奇数
+ 交换 nums[left] 和 nums[right] .
+ 重复上述操作，直到 left==right 
+ 实现
```C++
 vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left]%2 == 1) {//使用(nums[left]&1) != 1 会快一点点
                left ++;
                continue;//左边是奇数的话，left++，然后进入下一轮while往后判断
            }
            if (nums[right]%2 == 0) {
                right --;
                continue;//右边是偶数的话，right--，然后进入下一轮while往后判断
            }
            //进入此语句一定代表left指向偶数，right指向奇数，此时交换
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
```
4.快慢指针算法
+ 定义快慢双指针 fast 和 low ，fast 在前，low 在后 .
  - fast 的作用是向前搜索奇数位置，low 的作用是指向下一个奇数应当存放的位置
  - fast 向前移动，当它搜索到奇数时，将它和 nums[low] 交换，此时 low 向前移动一个位置 .
+ 重复上述操作，直到 fast 指向数组末尾 .
+ 实现
```C++
vector<int> exchange(vector<int>& nums) {
        int low = 0;
        int fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] & 1) {
                swap(nums[low], nums[fast]);
                low ++;
            }
            fast ++;
        }
        return nums;
    }
```
## 表示数值的字符串
1.题目
```
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"、"-1E-16"及"12e+5.4"都不是。
```
2.find_first_of和find_first_not_of函数以及string::nops
+ find_first_not_of()用法
```C++
  size_type find_first_not_of( const basic_string &str, size_type index = 0 );
  size_type find_first_not_of( const char *str, size_type index = 0 );
  size_type find_first_not_of( const char *str, size_type index, size_type num );
  size_type find_first_not_of( char ch, size_type index = 0 );
```
+ 在字符串中查找第一个与str中的字符都不匹配的字符，返回它的位置。搜索从index开始。如果**没找到就返回string::nops**
+ 在字符串中查找第一个与str中的字符都不匹配的字符，返回它的位置。搜索从index开始，最多查找num个字符。如果**没找到就返回string::nops**
+ 在字符串中查找第一个与ch不匹配的字符，返回它的位置。搜索从index开始。如果**没找到就返回string::nops**




3.一种简单的方法
+ 先去除字符串首尾的空格
+ 然后根据e划分指数和底数
+ 判断指数和底数是否合法即可
+ 实现
```C++
    bool isNumber(string s) {
        //1、从首尾寻找s中不为空格首尾位置，也就是去除首尾空格
        int i=s.find_first_not_of(' ');
        if(i==string::npos)return false;
        int j=s.find_last_not_of(' ');
        s=s.substr(i,j-i+1);
        if(s.empty())return false;

        //2、根据e来划分底数和指数
        int e=s.find('e');

        //3、指数为空，判断底数
        if(e==string::npos)return judgeP(s);

        //4、指数不为空，判断底数和指数
        else return judgeP(s.substr(0,e))&&judgeS(s.substr(e+1));
    }

    bool judgeP(string s)//判断底数是否合法
    {
        bool result=false,point=false;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]=='+'||s[i]=='-'){//符号位不在第一位，返回false
                if(i!=0)return false;
            }
            else if(s[i]=='.'){
                if(point)return false;//有多个小数点，返回false
                point=true;
            }
            else if(s[i]<'0'||s[i]>'9'){//非纯数字，返回false
                return false;
            }
            else{
                result=true;
            }
        }
        return result;
    }

    bool judgeS(string s)//判断指数是否合法
    {   
        bool result=false;
        //注意指数不能出现小数点，所以出现除符号位的非纯数字表示指数不合法
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='+'||s[i]=='-'){//符号位不在第一位，返回false
                if(i!=0)return false;
            }
            else if(s[i]<'0'||s[i]>'9'){//非纯数字，返回false
                return false;
            }
            else{
                result=true;
            }
        }
        return result;
    }

```
4.有限状态机算法
+ [见这篇分析](https://leetcode-cn.com/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/)
+ 实现
```C++
class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        int n = s.size();

        int state = 0;
        vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1}); // 合法的终止状态
        vector<vector<int> > transfer({
                {0,  1,  6,  2,  -1, -1},
                {-1, -1, 6,  2,  -1, -1},
                {-1, -1, 3,  -1, -1, -1},
                {8,  -1, 3,  -1, 4,  -1},
                {-1, 7,  5,  -1, -1, -1},
                {8,  -1, 5,  -1, -1, -1},
                {8,  -1, 6,  3,  4,  -1},
                {-1, -1, 5,  -1, -1, -1},
                {8,  -1, -1, -1, -1, -1},
                });

        for(int i = 0; i < n; ++i)
        {
            state = transfer[state][_make(s[i])];
            if(state < 0) return false;
        }
        return finals[state];
    }

private:
    int _make(const char& c)
    {
        switch(c)
        {
            case ' ': return 0;
            case '+': return 1;
            case '-': return 1;
            case '.': return 3;
            case 'e': return 4;
            default: return _number(c);
        }
    }

    int _number(const char& c)
    {
        if(c >= '0' && c <= '9')
            return 2;
        else
            return 5;
    }
};
```
## 链表中倒数第k个节点
1.题目
```
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

给定一个链表: 1->2->3->4->5, 和 k = 2.
返回链表 4->5.
```
2.分析
+ 比较简单，快慢双指针
+ 实现
```C++
    ListNode* getKthFromEnd(ListNode* head, int k) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        for(int fast_num=1;fast_num<k;fast_num++){
            fast = fast->next;
            if(fast == NULL){
                return nullptr;
            } 
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
```
## 反转链表
1.题目
```
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```
2.实现
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        ListNode* pre = head;
        while(pre){
            ListNode* temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};
```
## 合并两个排序的链表
1.题目
```
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```
2.实现
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while(l1 && l2){
            if(l1->val < l2->val){
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            }
            else{
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
        }
        if(l1){
            res->next = l1;
        }
        if(l2){
            res->next = l2; 
        }
        // while(l1){//这样虽然复杂，但也可以实现
        //     res->next = new ListNode(l1->val);
        //     res = res->next;
        //     l1 = l1->next;
        // }
        // while(l2){
        //     res->next = new ListNode(l2->val);
        //     res = res->next;
        //     l2 = l2->next;
        // }
        return head->next;
    }
};
```
## 树的子结构
1.题目
```
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。

给定的树 A:
     3
    / \
   4   5
  / \
 1   2
给定的树 B：
   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
```
2.分析
+ dfs(A, B) 函数：
  - 终止条件：
    - 当节点 B 为空：说明树 B 已匹配完成（越过叶子节点），因此返回 true ；
    - 当节点 A 为空且 B 不为空：说明已经越过树 A 叶子节点，即匹配失败，返回 false ；
    - 当节点 A 和 B 的值不同：说明匹配失败，返回 false ；
  - 返回值：
    - 判断 A 和 B 的左子节点是否相等，即 dfs(A.left, B.left) ；
    - 判断 A 和 B 的右子节点是否相等，即 dfs(A.right, B.right) ；
+ isSubStructure(A, B) 函数(题目里的主函数)：
  - 特例处理： 当 树 A 为空 或 树 B 为空 时，直接返回 false ；
  - 返回值： 若树 B 是树 A 的子结构，则必满足以下三种情况之一，因此用或 || 连接；
    - 以 节点 A 为根节点的子树 包含树 B ，对应 dfs(A, B)；
    - 树 B 是 树 A 左子树 的子结构，对应 isSubStructure(A.left, B)；
    - 树 B 是 树 A 右子树 的子结构，对应 isSubStructure(A.right, B)；
+ 实现
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL) return false;
        if(A == NULL && B) return false;
        // if(dfs(A,B)) return true;//一定要注意isSubStructure的退出条件，同时分开写也是可以的
        // return isSubStructure(A->left,B)||isSubStructure(A->right,B);
        return dfs(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool dfs(TreeNode* A, TreeNode* B){
        if(B == NULL) return true;
        if(A == NULL && B) return false;
        if(A->val == B->val){
            return dfs(A->left,B->left)&&dfs(A->right,B->right);
        }
        else{
            return false;
        }
    }
};
```
## 二叉树的镜像
1.题目
```
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```
2.实现
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        TreeNode* res = root;
        reverse(res);//这个递归执行完，实际上res还是指向整个树的根节点。
        return res;
    }
    void reverse(TreeNode* root){
        if(root == NULL) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        reverse(root->left);
        reverse(root->right);
    }
    //另一种做法本质和我的解法是一致的
    //     TreeNode* mirrorTree(TreeNode* root) {
    //     if(root){
    //         swap(root->left, root->right);
    //     }else return NULL;
    //     mirrorTree(root->left);
    //     mirrorTree(root->right);
    //     return root;
    // }
};
```
## 对称的二叉树
1.题目
```
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
```
2.分析
+ 对称二叉树定义： 对于树中 任意两个对称节点 L 和 R ，一定有：
  - L.val=R.val ：即此两对称节点值相等。
  - L.left=R.right ：即 L 的 左子节点 和 R 的 右子节点 对称；
  - L.right=R.left ：即 L 的 右子节点 和 R 的 左子节点 对称。
+ 实现
```C++
    bool helper(TreeNode* l, TreeNode* r){
        if(l && r)
            return (l->val == r->val) && helper(l->left, r->right) && helper(l->right, r->left);
        else if(!l && !r){
            return true;
        }
        else{
            return false;
        } 
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }
```
## 顺时针打印矩阵

1.题目
```
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
```
2.分析
+ 空值处理： 当 matrix 为空时，直接返回空即可。
+ 初始化： 矩阵 左、右、上、下 四个边界 l , r , t , b ，用于打印的结果列表 res 。
+ 循环打印： “从左向右、从上向下、从右向左、从下向上” 四个方向循环，每个方向打印中做以下三件事 （各方向的具体信息见下表） ；
+ 根据边界打印，即将元素按顺序添加至列表 res 尾部；
+ 边界向内收缩 1 （代表已被打印）；
+ 判断是否打印完毕（边界是否相遇），若打印完毕则跳出。
+ 返回值： 返回 res 即可。
+ 实现
```C++
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return {};
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        int x = 0;
        vector<int> res((right+1)*(bottom+1));
        while(1){
            for(int i=left;i<=right;i++) res[x++] = matrix[top][i];//左到右
            if(++top > bottom) break;
            for(int i=top;i<=bottom;i++) res[x++] = matrix[i][right];//上到下
            if(left>--right) break;
            for(int i=right;i>=left;i--) res[x++] = matrix[bottom][i];//右到左
            if(top>--bottom) break;
            for(int i=bottom;i>=top;i--) res[x++] = matrix[i][left];//下到上
            if(++left>right) break;
        }
        return res;
    }
```
## 包含min函数的栈
1.题目
```
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```
2.实现
```C++
class MinStack {
public:
    stack<int> res;
    stack<int> mini;

    /** initialize your data structure here. */
    MinStack() {
        mini.push(INT_MAX);
    }
    
    void push(int x) {
        res.push(x);
        if(x<mini.top()){
            mini.push(x);
        }
        else{
            mini.push(mini.top());
        }
    }
    
    void pop() {
        res.pop();
        mini.pop();
    }
    
    int top() {
        return res.top();
    }
    
    int min() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```
## 栈的压入、弹出序列
1.题目
```
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
```
2.实现
```C++
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> simulation;
        int ptr = 0;
        for(auto num:pushed){
            simulation.push(num);
            //这个while是核心，可以在pushed栈顶和poped当前指针元素一致时，一直弹出
            while(!simulation.empty() && simulation.top()==popped[ptr]){
                simulation.pop();
                ptr++;
            }
        }
        if(ptr == popped.size()){
            return true;
        }
        else{
            return false;
        }
    }
```
## 复杂链表的复制

1.
```
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
```
2.利用hashmap的实现
```C++
        Node* copyRandomList(Node* head) {
        if(head==NULL)  return head;
        unordered_map<Node*,Node*>mp;
        Node *t=head;
        while(t!=NULL){
            mp[t]=new Node(t->val);
            t=t->next;
        }
        t=head;
        while(t!=NULL){
            if(t->next){
                mp[t]->next=mp[t->next];
            }
            if(t->random){
                mp[t]->random=mp[t->random];
            }
            t=t->next;
        }
        return mp[head];
    }
```
## 从上到下打印链表
1.题目
```
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：
[3,9,20,15,7]
```
2.实现
```C++
    queue<TreeNode*> res;
    vector<int> levelOrder(TreeNode* root) {
        if(root == NULL) return{};
        vector<int> ans;
        res.push(root);
        while(!res.empty()){
            auto node = res.front();
            res.pop();
            ans.push_back(node->val);
            if(node->left){
                res.push(node->left);
            }
            if(node->right){
                res.push(node->right);
            }
        }
        return ans;
    }
```
## 最小的k个数

1.题目
```
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
```
2.实现
+ 方法一:
```C++
//用一个大根堆实时维护数组的前 k 小值。首先将前 k 个数插入大根堆中，随后从第 k+1 个数开始遍历，如果当前遍历到的数比大根堆的堆顶的数要小，
//就把堆顶的数弹出，再插入当前遍历到的数。最后将大根堆里的数存入数组返回即可。
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>vec(k, 0);
        if (k == 0) return vec; // 排除 0 的情况
        priority_queue<int>Q;
        for (int i = 0; i < k; ++i) Q.push(arr[i]);
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
```
+ 方法二
```C++
//归并排序
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        vector<int> ans;
        res =arr;
        int left = 0;
        int right = res.size()-1;
        mergesort(res,left,right);
        for(int i=0;i<k;i++){
            ans.push_back(res[i]);
        }
        return ans;
    }
    void mergesort(vector<int>& res, int left, int right){
        if(left>=right) return;
        int mid = (left+right)/2;
        mergesort(res,left,mid);
        mergesort(res,mid+1,right);
        int l = left;
        int r = mid+1;
        vector<int> temp;
        while(l<=mid&&r<=right){
            if(res[l]<res[r]){
                temp.push_back(res[l]);
                l++;
            }
            else{
                temp.push_back(res[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(res[l]);
            l++;
        }
        while(r<=right){
            temp.push_back(res[r]);
            r++;
        }
        copy(temp.begin(), temp.begin() + right-left+1, res.begin() + left);
    }
```
