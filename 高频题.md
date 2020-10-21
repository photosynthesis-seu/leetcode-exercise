# 目录
## 链表与二叉树模板
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
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    vector<ListNode*> lists(n);
    for(int i = 0; i < n; i++){
        int num;
        ListNode* head = new ListNode(-1);
        ListNode* res = head;
        while(cin>>num){
            ListNode* mem = new ListNode(num);
            res->next = mem;
            res = res->next;
            if(getchar() == '\n') break;
        }
        ListNode* list = sortList(head->next);
        lists.push_back(list);
    }

    ListNode* ans = mergeLists(lists);
    while(ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    return 0;
}
```
## 链表基础操作

[leetcode链表题目整理](https://leetcode-cn.com/circle/article/YGr54o/)
- [单链表操作](#单链表操作)
- [双向链表操作](#双向链表操作)


## 链表
- [从尾到头打印链表](#从尾到头打印链表)//双指针反转链表、辅助栈、巧妙的递归函数
- [删除链表的节点](#删除链表的节点)//注意考虑所有情况
- [链表中倒数第k个节点](#链表中倒数第k个节点)//快慢双指针
- [反转链表](#反转链表)//常规操作，反转链表
- [反转链表的一部分](#反转链表的一部分)//递归和迭代两种方法
- [合并两个排序的链表](#合并两个排序的链表)//关注哨兵节点
- [两个链表的第一个公共节点](#两个链表的第一个公共节点)//神奇的双指针，有点类似最小公倍数
- [环形链表](#环形链表)//快慢指针，包括判断环的位置(快慢指针的交点不一定是环的起始点)
- [合并k个排序链表](#合并k个排序链表)
- [链表排序](#链表排序)
- [复杂链表的复制](#复杂链表的复制)//深拷贝与浅拷贝的区别
- [旋转链表](#旋转链表)//双指针
- [去除链表中重复元素](#去除链表中重复元素)//双指针、快慢指针
- [k个一组翻转链表](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/%E9%99%84%E5%BD%952.md#k个一组翻转链表)//难：两个全局指针，两个局部指针、反转链表

## 二叉树
- [二叉树前中后序遍历的非递归方法](#二叉树前中后序遍历的非递归方法)
- [重建二叉树](#重建二叉树)//前序遍历、中序遍历、递归函数DFS
- [平衡二叉树](#平衡二叉树)//都是用递归，但是注意从上到下和从下到上递归的时间复杂度天差地别！
- [树的子结构](#树的子结构)//巧妙的使用两种递归（就不使用回溯算法了）
- [二叉树的镜像](#二叉树的镜像)//递归算法
- [对称的二叉树](#对称的二叉树)
- [从上到下打印二叉树](#从上到下打印二叉树)//广度优先、队列
- [从上到下打印二叉树II](#从上到下打印二叉树II)//带计数的队列
- [从上到下打印二叉树III](#从上到下打印二叉树III)//带计数与flag的队列！
- [二叉搜索树的后序遍历树](#二叉搜索树的后序遍历树)//根据后序遍历的性质构建递归函数
- [序列化二叉树](#序列化二叉树)//队列,ostringstream,istringstream,stoi()函数，重点题目！把一个数组或者字符串转化为二叉树的典型方法！！！
- [序列化和反序列化二叉搜索树](#序列化和反序列化二叉搜索树)
- [二叉树中和为某一值的路径](#二叉树中和为某一值的路径)//回溯算法，BFS广度优先遍历
- [二叉树中和为某一直的路径（不一定根节点开始）](#路径总和III)//带选择的路径回溯
- [二叉搜索树与双向链表](#二叉搜索树与双向链表)//DFS,双向链表的初始化表头(要在递归里面)！
- [二叉搜索树的最近公共祖先](#二叉搜索树的最近公共祖先)//充分利用二叉搜索树的性质
- [二叉树的最近公共祖先](#二叉树的最近公共祖先)//递归算法
- [二叉搜索树的第k大节点](#二叉搜索树的第k大节点)//使用中序遍历
- [二叉树的深度](#二叉树的深度)//BFS算法（使用计数队列统计层数）、DFS算法（回溯算法）
- [二叉树的最大路径和](#二叉树的最大路径和)
- [二叉树的最长同值路径](#二叉树的最长同值路径)//借鉴最大路径和的思路
- [二叉树展开为链表](#二叉树展开为链表)//(有较为容易想到的前序遍历+vector存储，以及非常难的三指针原地翻转)
- [将有序数组转换为二叉搜索树](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/%E9%99%84%E5%BD%952.md#将有序数组转换为二叉搜索树)//递归就行了
- [有序链表转换为二叉搜索树](#有序链表转换为二叉搜索树)//不同于将有序数组转换为二叉搜索树，需要利用链表的性质，进行分治+中序遍历
- [二叉树的直径](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/%E9%99%84%E5%BD%952.md#%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%9B%B4%E5%BE%84)
- [二叉树的宽度](#二叉树的宽度)//用pair记录节点和对应的编号
- [二叉树的所有路径](#二叉树的所有路径)//遍历所有路径[leetcode257](https://leetcode-cn.com/problems/binary-tree-paths/solution/er-cha-shu-de-suo-you-lu-jing-by-leetcode-solution/)
- [二叉树完全性的检验](#二叉树完全性的检验)//层序遍历
- [合并二叉树](#合并二叉树)//递归

## 数组处理
- [最大连续1的个数III](#最大连续1的个数III)//滑动窗口与双指针
- [最长递增子序列](#最长递增子序列)//动态规划。优化时加二分查找
- [全部的递增子序列](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/%E9%99%84%E5%BD%952.md#递增子序列)/注意回溯算法的剪枝！！
- [最长公共子序列](#最长公共子序列)
- [信封嵌套问题](#信封嵌套问题)//最长递增子序列的二维进阶版！
- [数组中的重复数字](#数组中的重复数字)
- [数组中的逆序对](#数组中的逆序对)//归并算法
- [二维数组中的查找](#二维数组中的查找)//从左下角开始查找（注意这种方法的逻辑原理）
- [旋转数组的最小数字](#旋转数组的最小数字)//二分查找、双指针算法、需要通过数组最右边值判断（特殊情况判断->大量数字相等时，right--）
- [调整数组顺序使奇数位于偶数前面](#调整数组顺序使奇数位于偶数前面) //典型的首尾双指针、快慢指针题目，一定要会！！
- [最小的k个数](#最小的k个数)//大根堆、快速排序与归并排序算法的排坑（注意归并排序的返回条件）
- [连续子数组的最大和](#连续子数组的最大和)//简单的动态规划
- [和为s的两个数字](#和为s的两个数字)//hash表算法和双指针算法都需要了解！
- [把数组排成最小的数](#把数组排成最小的数)//重载sort函数，此题关键在于数学思路要明确，实现不难
- [构建乘积数组](#构建乘积数组)//一种经典方法，从左到右，从右到左来回遍历；一遍用一个数组，一遍用一个整数
- [数组中出现次数超过一半的数字](#数组中出现次数超过一半的数字)//摩尔投票法，排序法，以及hash表查找法
- [在排序数组中查找数字I](#在排序数组中查找数字I)//两种二分查找，一定注意边界判断！
- [数组中数字出现的次数II](#数组中数字出现的次数II)//位运算算法，一定需要掌握
- [数据流中的中位数](#数据流中的中位数)//优先队列、大顶堆与小顶堆（困难！）
- [和为k的子数组](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/%E9%99%84%E5%BD%952.md#和为k的子数组)//双指针思想，巧妙的前缀和，哈希表unordered_map的应用
- [有序数组中去除重复元素](#有序数组中去除重复元素)//利用双指针的快慢指针，原地去除重复元素
- [0～n-1中缺失的数字](#0到n-1中缺失的数字)//这道题的二分查找非常凶险！为了避免对特殊情况判断，实现细节很不同，慎用！
- [字典序排数](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/%E9%99%84%E5%BD%952.md#字典序排数)//给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9]
- [长度最小的数组](#长度最小的数组)给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。
- [合并N个有序数组](#合并N个有序数组)//使用小顶堆和自定义结构体实现（因为没有链表指向下一个元素，所以要记录遍历到的数组下表）


## 栈、队列、单调队列
- [使用数组和链表实现队列](#使用数组和链表实现队列)
- [用两个栈实现队列](#用两个栈实现队列)//一个栈进入后全部转移到另一个辅助栈
- [栈的压入、弹出序列](#栈的压入、弹出序列)//模拟栈的压入和弹出，那个while判断是核心！！！
- [包含min函数的栈](#包含min函数的栈)//双栈，注意使用辅助栈
- [递归反转栈中元素](#递归反转栈中元素)
- [队列的最大值](#队列的最大值)//队列与双端队列的实现，还是单调队列！！
- [滑动窗口的最大值](#滑动窗口的最大值)//难题！优先队列解法、单调队列解法（使用双端队列实现）
- [接雨水问题](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/README.md#%E6%8E%A5%E9%9B%A8%E6%B0%B4%E9%97%AE%E9%A2%98)//动态规划解法、单调递减栈解法！！

## 动态规划
[leetcode动态规划题目整理](https://leetcode-cn.com/circle/article/NfHhXD/)
- [爬楼梯问题](#爬楼梯问题)
- [鸡蛋掉落](#鸡蛋掉落)
- [股票的最大利润](#股票的最大利润)//系列动态规划问题，一定要重视
- [接雨水问题](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/README.md#%E6%8E%A5%E9%9B%A8%E6%B0%B4%E9%97%AE%E9%A2%98)//动态规划解法、单调递减栈解法！！
- [最长公共子序列](#最长公共子序列)

## 双指针&滑窗
- [三数之和](#三数之和)
- [和为s的两个数字](#和为s的两个数字)//hash表算法和双指针算法都需要了解！
- [最大连续1的个数III](#最大连续1的个数III)//滑动窗口与双指针

## 字符串系列
- [字符串的排列](#字符串的排列)//回溯算法
- [表示数值的字符串](#表示数值的字符串)//几个神奇的函数find_first_not_of...,根据e划分指数和底数
- [重复的子字符串](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/%E9%99%84%E5%BD%952.md#重复的子字符串)//一个非空的字符串，判断它是否可以由它的一个子串重复多次构成
- [最长不含重复字符的子字符串](#最长不含重复字符的子字符串)//双指针算法->多种算法进行优化、进阶
- [最小覆盖子串](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/%E9%99%84%E5%BD%952.md#最小覆盖子串)//比较难的滑动窗口算法！
- [第一个只出现一次的字符](#第一个只出现一次的字符)//hash表O(2N)->O(N)
- [翻转单词顺序](#翻转单词顺序)//istringstream和stack的配合使用！
- [反转字符串中的单词III](#反转字符串中的单词III)//原地翻转
- [左旋转字符串](#左旋转字符串)//三种切片的方法，substr(star,lenght):起始下标和子串长度
- [最长回文子串](https://github.com/photosynthesis-seu/leetcode-exercise#%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2)//动态规划或双指针算法！双指针空间复杂度更低
- [最长回文子序列](#最长回文子序列)
- [回文字符串总数](#回文字符串总数)//中心拓展法
- [最长公共子序列与最长公共子串](#最长公共子序列与最长公共子串)//动态规划

## 字符串和数字的相互转换
- [把数字翻译成字符串](#把数字翻译成字符串)//经典的动态规划，空间复杂度从O（N）优化到O（1），一定要关注
- [把字符串转换成整数](#把字符串转换成整数)//需要细致考虑所有情况，有限状态机，istringstream
- [字符串相加](#字符串相加)//使用字符串实现大数相加
- [字符串相减](#字符串相减)//大数相减
- [字符串相乘](#字符串相乘)
- [两数相除](#两数相除)

## 经典算法
- [数组的子集、排列、组合问题](#数组的子集排列组合问题)
- [LRU缓存机制](#LRU缓存机制)//哈希表，双向链表，自定义双向链表添加头结点、移动至头结点等等，带自定义结构体-双向链表的Unordered_map
- [LFU缓存机制](#LFU缓存机制)
- [接雨水问题](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/README.md#%E6%8E%A5%E9%9B%A8%E6%B0%B4%E9%97%AE%E9%A2%98)//动态规划解法、单调递减栈解法！！
- [判断一个点是否在三角形内](#判断一个点是否在三角形内)
- [生成100以内不重复的随机数](#生成100以内不重复的随机数)
- [随机洗牌](#随机洗牌)
- [memcpy与strcpy](#memcpy与strcpy)
- [高效数组排序](#高效数组排序)//把非0和0元素放至数组两侧
- [24点游戏](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/%E9%99%84%E5%BD%952.md#24点游戏)
- [判断一个数是否为2的n次方和求两个数的最小公倍数](#判断一个数是否为2的n次方)
- [C语言实现itoa](#C语言实现itoa)//C语言实现itoa
- [逆波兰表达式](#逆波兰表达式)
- [验证IP地址](#验证IP地址)//包括IPV4和IPv6
- [版本号比较](#版本号比较)//分割数组，逐步比较
- [颜色分类](#颜色分类)//荷兰旗问题

## 贪心算法
- [无重叠区间](#无重叠区间)
- [合并区间](#合并区间)
- [区间交集](#区间交集)


## 暂未分类
- [矩阵中的路径](#矩阵中的路径)//dfs算法+典型模板、回溯算法、有点动态规划那味
- [No.14 剪绳子I](#剪绳子I)//关注严格的数学原理推导、动态规划
- [No.15 二进制中1的个数](#二进制中1的个数)//n&(n-1),运算符优先级：先算术运算，后移位运算，最后位运算
- [No.16 数值的整数次方](#数值的整数次方)//快速幂法，二分法
- [No.17 打印从1到最大的n位数](#打印从1到最大的n位数)//pow()函数、大数解法
- [No.19 正则表达式匹配](#正则表达式匹配)//比较复杂的动态规划
- [No.29 顺时针打印矩阵](#顺时针打印矩阵)//需要非常细致的分类讨论
- [No.43 1~n整数中1出现的次数](#1~n整数中1出现的次数)//严谨的分情况讨论，一定要从低位向高位遍历
- [No.44 数字序列中某一位的数字](#数字序列中某一位的数字)//分类讨论，找数学规律细致实现，使用to_string会超时
- [No.47 礼物的最大价值](#礼物的最大价值)//典型的二维动态规划
- [No.49 丑数](#丑数)//带有数学技巧的动态规划,有关公因数的题目均可以参考！
- [No.60 n个骰子的点数](#n个骰子的点数)//标准的动态规划和压缩数组的优化算法、类似背包问题
- [No.61 扑克牌中的顺子](#扑克牌中的顺子)//数学思想，hash表
- [No.62 圆圈中最后剩下的数字](#圆圈中最后剩下的数字)//环形链表超时，约瑟夫环问题
- [No.64 求1+...+n](#求1+...+n)//技巧性问题
- [No.65 不用加减乘除做加法](#不用加减乘除做加法)//位运算与异或的结合




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
4.位运算

```C++
int missingNumber(int[] nums) {
    int n = nums.length;
    int res = 0;
    // 先和新补的索引异或一下
    res ^= n;
    // 和其他的元素、索引做异或
    for (int i = 0; i < n; i++)
        res ^= i ^ nums[i];
    return res;
}
```

## 二维数组中的查找
1.题目
```
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```
2.实现
```C++
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
                if (matrix.size() == 0){
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m - 1;
        int col = 0;
        while (row >=0 && col < n){
            if(matrix[row][col] < target){
                col += 1;
            }
            else if(matrix[row][col] > target){
                row -= 1;
            }
            else{
                return true;
            }
        }
        return false;
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
## 用两个栈实现队列
1.题目
```
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
```
2.实现
```C++
class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {}
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(stack1.empty()&&stack2.empty())return -1;
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());  
                stack1.pop();
            }
        }
        int res=stack2.top();
        stack2.pop();
        return res;
    }

    //     if (stack1.empty()) return -1; 
    //     while (!stack1.empty()){ // 1 -> 2
    //         int tmp = stack1.top();
    //         stack1.pop();
    //         stack2.push(tmp);
    //     }
    //     // delete head
    //     int res = stack2.top();
    //     stack2.pop();
    //     while (!stack2.empty()){ // 1 <- 2
    //         int temp = stack2.top();
    //         stack2.pop();
    //         stack1.push(temp);
    //     }
    //     return res;
    // }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
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
+ 递归的方法
```C++
ListNode* reverse(ListNode* head) {
    if (head->next == null) return head;
    ListNode* last = reverse(head->next);
    head->next->next = head;
    head->next = null;
    return last;
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
2.非递归实现
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
3.递归实现
```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
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
3.非递归迭代的实现
+ 模型：使用队列模拟二叉树的层次遍历。循环结束条件：队列为空。实现操作：交换队首结点的左右子树
```C++
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                continue;
            }
            swap(node->left, node->right);
            q.push(node->left);
            q.push(node->right);
        }
        return root;
    }
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
+ 非递归迭代的方法
```C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root ==NULL)
            return true;
        //用队列保存节点
        queue<TreeNode*> q;
        //将根节点的左右孩子放到队列中
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            //从队列中取出两个节点，再比较这两个节点
            TreeNode* A = q.front();
            q.pop();
            TreeNode* B = q.front();
            q.pop();
            //如果两个节点都为空就继续循环，两者有一个为空就返回false
            if (A==NULL && B==NULL)
                continue;
            if (A==NULL || B==NULL)
                return false;
            if (A->val != B->val)
                return false;
            //将左子树的左孩子， 右子树的右孩子放入队列
            q.push(A->left);
            q.push(B->right);
            //将左子树的右孩子，右子树的左孩子放入队列
            q.push(A->right);
            q.push(B->left);
        }
        return true;
    }
};
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
## 从上到下打印二叉树
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
## 从上到下打印二叉树II

1.题目
```
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [20,9],
  [15,7]
]
```
2.实现
```C++
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> res;
        res.push(root);
        while(!res.empty()){
            int length = res.size();
            vector<int> temp;
            for(int i=0;i<length;i++){
                auto node = res.front();
                res.pop();
                temp.push_back(node->val);
                if(node->left){
                    res.push(node->left);
                }
                if(node->right){
                    res.push(node->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
```
## 从上到下打印二叉树III
1.题目
```
实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
```
2.实现
```C++
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> res;
        bool flag = false;
        res.push(root);
        while(!res.empty()){
            int length = res.size();
            vector<int> temp;
            for(int i=0;i<length;i++){
                auto node = res.front();
                res.pop();
                temp.push_back(node->val);
                if(node->left){
                    res.push(node->left);
                }
                if(node->right){
                    res.push(node->right);
                }
            }
            if(flag){
                reverse(temp.begin(),temp.end());
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
```
## 二叉搜索树的后序遍历树

1.题目
```
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
输入: [1,6,3,2,5]
输出: false

输入: [1,3,2,6,5]
输出: true
```

2.分析
+ 终止条件： 当 left≥root ，说明此子树节点数量 ≤1 ，无需判别正确性，因此直接返回 true ；
+ 递推工作：
  - 划分左右子树： 遍历后序遍历的 [left,root] 区间元素，寻找第一个大于根节点 的节点，索引记为 right 。此时，可划分出左子树区间[left,right−1] 、右子树区间 [right,root−1] 、根节点索引 root 。
  - 判断是否为二叉搜索树：
    - 左子树区间 [left,right−1] 内的所有节点都应 < postorder[root] 。而划分左右子树的步骤已经保证左子树区间的正确性，因此只需要判断右子树区间即可。
    - 右子树区间 [right,root−1] 内的所有节点都应 > postorder[root] 。实现方式为遍历，当遇到 ≤postorder[root] 的节点则跳出；则可通过 right==root? 判断是否为二叉搜索树。
  - 返回值： 所有子树都需正确才可判定正确，因此使用 与逻辑符 && 连接。
    - right==root ： 判断 此树 是否正确。
    - helper(left,right−1)： 判断 此树的左子树 是否正确。
    - helper(right,root−1) ： 判断 此树的右子树 是否正确。
+ 实现
```C++
   bool verifyPostorder(vector<int>& postorder) {
        int len = postorder.size();
        return helper(postorder,0,len-1);
    }
    //left,right,root代表目前二叉搜索树的根节点的数组下标以及根节点左、右子树根节点的数组下标
    bool helper(vector<int>& postorder, int left, int root){
        if(left>=root) return true;//注意递归函数的跳出条件
        int temp = left;//不能直接用left,否则之后使用递归函数时left的值就会跑偏了！！right同理
        while(postorder[temp]<postorder[root]){
            temp++;
        }
        int right = temp;//找到第一个比根节点值大的数的下标，就是它的右子树的根节点下标
        while(postorder[temp]>postorder[root]){
            temp++;
        }
        if(temp == root && helper(postorder,left,right-1) && helper(postorder,right,root-1)){
            return true;
        }
        else{
            return false;
        }
    }
```
## 二叉树中和为某一值的路径
1.题目
```
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
```
2.实现
```C++
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return {};
        vector<int> res;
        int now = 0;
        helper(root,res,now,sum);
        return ans;
    }
    void helper(TreeNode* root, vector<int>& res, int now, int sum){
        res.push_back(root->val);
        now +=  root->val;
        if(now == sum && root->left == NULL && root->right == NULL){
            ans.push_back(res);
        }
        // else if(now>sum){
        //     res.pop_back();
        //     return;
        // }这一段不能加，因为测试用例中节点可能为负数！！
        if(root->left){
            helper(root->left,res,now,sum);
        }
        if(root->right){
            helper(root->right,res,now,sum);
        }
        res.pop_back();
        return;
    }
```
## 二叉搜索树与双向链表
1.分析
```
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
```
2.实现
```C++
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        Node* head = NULL;//用来存储头结点
        Node* pre = NULL;//pre指针用来存放当前访问节点的上一个节点，结束时位于链表末尾
        helper(root,head,pre);
        head->left = pre;//头节点的左指针指向末尾
        pre->right = head;//尾节点的右指针指向头
        return head;
    }
    void helper(Node* root, Node*& head, Node*& pre){//利用中序遍历访问二叉树的同时构建双向链表
        if(root == NULL) return;
        helper(root->left,head,pre);
        //一定要在这里初始化头指针和pre指针，因为只有在这里会中序递归到第一个左叶子节点作为链表头
        if(head == NULL){
            head = root;
            pre = root;
        }
        else{
            root->left = pre;
            pre->right = root;
            pre = root;
        }
        helper(root->right,head,pre);
    }
```
## 序列化二叉树
1.题目
```
请实现两个函数，分别用来序列化和反序列化二叉树。
你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
```
2.sstream,fstream,iostream相关
+ 一些知识点：
  - sstream包括istringstream和ostringstream
  - stoi需要包含头文件#include<string>;atoi需要包含头文件#include<sctdlib>
  - stoi(string)参数是一string类型，当字符串不合法时，会报错;
  - atoi(char*)参数是char*类型，即c字符串，当字符串非法时,他会从字符串开始寻找正负号小数点或者数字，遇到非法字符时停下.例如“123HD23330”通过调用atoi返回值为123，而stoi则会直接报错

+ (1)iostream处理控制台IO；(2)fstream处理命名文件IO；(3)stringstream完成内存string的IO.[具体见这篇文章](https://blog.csdn.net/scpw99/article/details/81127851)
+ [stringstream简介](https://blog.csdn.net/zhenguo26/article/details/80716075)
+ [使用sstream读取字符串中的数字](https://blog.csdn.net/zdlnlhmj/article/details/79462770?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase)

3.实现
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp) {
                out<<tmp->val<<" ";
                q.push(tmp->left);
                q.push(tmp->right);
            } else {
                out<<"null ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        string val;
        vector<TreeNode*> vec;
        while (input >> val) {
            if (val == "null") {
                vec.push_back(NULL);
            } else {
                vec.push_back(new TreeNode(stoi(val)));
            }
        }
        int j = 1;                                          // i每往后移动一位，j移动两位，j始终是当前i的左子下标
        for (int i = 0; j < vec.size(); ++i) {              // 肯定是j先到达边界，所以这里判断j < vec.size()
            if (vec[i] == NULL) continue;                   // vec[i]为null时跳过。
            if (j < vec.size()) vec[i]->left = vec[j++];    // 当前j位置为i的左子树
            if (j < vec.size()) vec[i]->right = vec[j++];   // 当前j位置为i的右子树
        }
        return vec[0];
    }
};
```
## 数组中出现次数超过一半的数字
1.题目
```
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
```
2.实现
```C++
    int majorityElement(vector<int>& nums) {
        //方法一：排序遍历
    //     int len = nums.size();
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<(len+1)/2;i++){
    //         if(nums[i] == nums[i+len/2] ){
    //             return nums[i];
    //         }
    //     }
    //     return 0;
        //方法二：hash表
    // unordered_map<int,int> res;
    // int len = nums.size();
    // for(auto num:nums){
    //     if(++res[num]>len/2){
    //         return num;
    //     }
    // }
    // return 0;
        //方法三：摩尔投票法
        int vote_sum = 1;
        int most = nums[0];
        for(int i=1;i<nums.size();i++){
            if(vote_sum == 0) most = nums[i];
            if(nums[i] == most) vote_sum += 1;
            if(nums[i] != most) vote_sum += -1;
        }
        return most;
    }
```
## 数据流中的中位数

1.题目
```
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：
输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
```
2.分析
+ [这篇解析说的非常好](https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/solution/mian-shi-ti-41-shu-ju-liu-zhong-de-zhong-wei-shu-y/)
+ 实现
```C++
class MedianFinder {
    priority_queue<int> left;// 大顶堆
    priority_queue<int, vector<int>, greater<int>> right;//小顶堆
    //将较小的部分存在大根堆，较大的部分存在小根堆
    //大根堆元素个数 - 小根堆元素个数 = 0 或者 1  
    public:
    
    // Adds a number into the data structure.
    void addNum(int num)
    {
        left.push(num);// 先加到大顶堆，然后把大根堆的top给小根堆，保证数据有序
        right.push(left.top());
        left.pop();
                                            
        if (left.size() < right.size()) {//保证大顶堆的元素个数不小于小根堆
            left.push(right.top());
            right.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        if(left.size()>right.size()){
            return double(left.top());
        }
        else{
            return (left.top()+right.top())*0.5;
        }
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
## 连续子数组的最大和

1.题目
```
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```
2.实现
```C++
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int ans = nums[0];
        vector<int> dp(len);
        dp[0] = nums[0];
        for(int i=1;i<len;i++){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
        }
        for(auto cur:dp){
            ans = max(ans,cur);
        }
        return ans;
    }
```
## 1~n整数中1出现的次数
1.题目
```
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

输入：n = 12
输出：5
输入：n = 13
输出：6
```
2.分析
+ [详见这篇分析](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/c-cong-ge-wei-bian-li-dao-zui-gao-wei-yi-ci-qiu-ji/)
+ [以及这篇题解](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/)
+ 实现
```C++
    //一定要从低位向高位遍历，不能从高位向低位遍历
    int countDigitOne(int n) {
       int count = 0;
       long i = 1;//指向遍历的位数，如i=1即个位，i=10即十位，...，因为n可以有31位，所以10^31用long存储
       while(n/i!=0){
           //n/i控制遍历的次数，将所有的位数都遍历完毕
            long high = n/(10*i);//将当前位之前的所有高位都存在high中
            long cur = (n/i)%10;//将当前位记录在cur中，即我们每次都需要统计当前位上1出现的次数
            long low = n-(n/i)*i;
            if(cur == 0){
                count += high * i;
            } else if(cur == 1){
                count += high * i + low + 1;
            } else {
                count += high * i + i;
            }
            i = i * 10;//准备遍历下一位
       }
       return count;
    }
```
## 数字序列中某一位的数字
1.题目
```
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
请写一个函数，求任意第n位对应的数字。

输入：n = 3
输出：3

输入：n = 11
输出：0
```
2.分析
+ [见这篇文章](https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/zhe-shi-yi-dao-shu-xue-ti-ge-zhao-gui-lu-by-z1m/)
+ 实现
```C++
    // 测试用例一半会超时
    // int findNthDigit(int n) {
    //     string res;
    //     int i =0;
    //     while(res.size()<n+1){
    //         res += to_string(i);
    //         i++;
    //     }
    //     int ans = res[n] - '0';
    //     return ans;
    // }
        int findNthDigit(int n) {
        if(n<10) return n;
        int base=1;
        while(n>9*pow(10,base-1)*base){
            n-=9*pow(10,base-1)*base;
            base++;
        }//计算n在哪个位数区间
        int res=pow(10,base-1)+n/base;
        int mod=n%base;
        if(mod==0) return (res-1)%10;
        else return res/(int)pow(10,base-mod)%10;
    }
```
## 把数组排成最小的数
1.题目
```
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

输入: [10,2]
输出: "102"

输入: [3,30,34,5,9]
输出: "3033459"
```
2.分析
+ [见这篇解析](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/)
+ 实现
```C++
    static bool cmp1(string& str1,string& str2){
        return str1+str2 < str2+str1;
    }
    string minNumber(vector<int>& nums) {
        vector<string> res;
        string ans;
        for(auto num:nums){
            res.push_back(to_string(num));
        }
        //sort(res.begin(),res.end(),cmp1);这两种重载sort函数的方法都可以
        sort(res.begin(),res.end(),[](string& str1,string& str2){return str1+str2 < str2+str1;});
        for(auto str:res){
            ans += str;
        }
        return ans;
    }
```
## 把数字翻译成字符串
1.题目
```
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
```
2.分析
+ [这篇解答很好](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/mian-shi-ti-46-ba-shu-zi-fan-yi-cheng-zi-fu-chua-6/)
+ 实现(两种实现都需要掌握)
```C++
    // int translateNum(int num) {
    //     string res = to_string(num);
    //     int a = 1, b = 1;
    //     int c;
    //     for(int i=2;i<=res.size();i++){
    //         string temp = res.substr(i-2,2);
    //         if(temp >= "10" && temp<= "25"){
    //             c = a + b;
    //         }
    //         else{
    //             c = b;
    //         }
    //         a = b;
    //         b = c;
    //     }
    //     return b;
    // }
    int translateNum(int num) {
       int a = 1, b = 1;
       int c;
       int x, y = num%10;
       while(num){
            num /= 10;
            x = num%10;
            int temp = 10*x+y;
            if(temp >=10 && temp <= 25){
                c = a+b;
            }
            else{
                c = b;
            }
            a = b;
            b = c;
            y = x;
       }
       return b;
    }
```
## 礼物的最大价值
1.题目
```
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
```
2.实现
```C++
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols));
        dp[0][0] = grid[0][0];
        for(int i=1;i<cols;i++){
            dp[0][i] = grid[0][i]+dp[0][i-1];
        }
        for(int j=1;j<rows;j++){
            dp[j][0] = grid[j][0]+dp[j-1][0];
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                // if(i==0&&j==0) continue;
                // if(i==0) dp[i][j] = grid[i][j] + dp[i][j-1];
                // if(j==0) dp[i][j] = grid[i][j] = dp[i-1][j];
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
```
## 最长不含重复字符的子字符串
1.题目
```
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```
2.分析
+ [这篇解析非常好](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/c-san-chong-jie-fa-by-yizhe-shi-2/)
+ 移动左右指针，我们其实可以更大步的移动左指针，一旦检测到重复字符，左指针可以直接跳到重复部分，这是很自然的，不重复子串肯定不会把重复部分包含进去。
而检测是否重复其实不必要使用set了，因为一共有127个字符，所以直接开辟128长度的数组即可。首先把每个字符的对应值设为 -1。每次把 m[s[i]] 设置为 i，是为了能够让左指针及时跳到重复部分。在 w 处检测到重复，所以left跳到第一个 w 处，然后中最后一个 w 处又检测到重复，所以 left 跳到第二个 w 处。之所以跳到前一个重复的位置，是因为 [i,j] 之间的长度为 j - i + 1，所以就没跳到重复位置的右边，当然都是可以的。
+ 实现
```c++
    // 使用unordered_set的一种双指针算法
    // int lengthOfLongestSubstring(string s) {
    //     unordered_set<char> mem;
    //     int left=0,right=0;
    //     int len = s.size();
    //     int res=0;
    //     for(;right<len;right++){
    //         if(mem.find(s[right]) == mem.end()){
    //             mem.insert(s[right]);
    //             res = max(res,right-left+1);
    //         }
    //         else{
    //             while(s[left] != s[right]){
    //                 mem.erase(s[left]);
    //                 left++;
    //             }
    //             left++;
    //         }
    //     }
    //     return res;
    // }

    //   也是使用unordered_set的双指针算法，比第一种算法看起来更直观一些
    //     int lengthOfLongestSubstring(string s) {
    //     unordered_set<char> mem;
    //     int left=0,right=0;
    //     int len = s.size();
    //     int res=0;
    //     for(;right<len;right++){
    //         while(mem.find(s[right]) != mem.end()){
    //             mem.erase(s[left]);
    //             left++;
    //         }
    //         mem.insert(s[right]);
    //         res = max(res,right-left+1);
    //     }
    //     return res;
    // }

    //一种最极致的优化算法
        int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int res = 0, left = -1;
        for(int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
```
## 丑数
1.题目
```
我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
```
2.分析
+ [这篇解答说的一清二楚！](https://leetcode-cn.com/problems/chou-shu-lcof/solution/chou-shu-ii-qing-xi-de-tui-dao-si-lu-by-mrsate/)
+ 实现
```C++
	int nthUglyNumber(int n) {
		vector<int> dp(n, 0);
		dp[0] = 1;
		int p2 = 0, p3 = 0, p5 = 0;
		for (int i = 1; i < n; i++){
			dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
			if (dp[i] == dp[p2] * 2) 
                p2++;
			if (dp[i] == dp[p3] * 3) 
                p3++;
			if (dp[i] == dp[p5] * 5) 
                p5++;
		}
		return dp[n - 1];
	}
```
## 第一个只出现一次的字符
1.题目
```
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

s = "abaccdeff"
返回 "b"
s = "" 
返回 " "
```
2.实现
+ [这篇解答很好](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/solution/c-zhong-gui-zhong-ju-de-92msjie-fa-ha-xi-by-gary_c/)
+ 实现
```C++
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> mm;
        for (char& ch : s) ++mm[ch];
        for (char& ch : s) if (mm[ch] == 1) return ch;
        return ' ';
    }
};
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> mm;
        int t[26] = { INT_MAX };
        for (int i = 0; i < s.size(); ++i) {
            ++mm[s[i]];
            t[s[i] - 'a'] = i;
        }

        char ans = ' ';
        int mint = INT_MAX;
        for(auto& p:mm) 
            if (p.second == 1 && t[p.first - 'a'] < mint) {
                ans = p.first;
                mint = t[p.first - 'a'];
            }
        return ans;
    }
};
```
## 两个链表的第一个公共节点

1.题目
```
输入两个链表，找出它们的第一个公共节点。

输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```
2.分析
+ 两个链表长度分别为L1+C、L2+C， C为公共部分的长度，第一个人走了L1+C步后，回到第二个人起点走L2步；第2个人走了L2+C步后，回到第一个人起点走L1步。 当两个人走的步数都为L1+L2+C时就两个家伙就相爱了
+ **必须用if(node1)而不是if(node1->next)，这样如果链表不相交，他们会同时指向NULL**
+ **可以理解为两条链表最后都指向了同一个 null （None）节点，代替了不相交的特殊情况。 非常的巧妙。**
+ 实现
```C++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while(node1 != node2){
            if(node1){//必须用if(node1)而不是if(node1->next)，这样如果链表不相交，他们会同时指向NULL
                node1 = node1->next;
            }
            else{
                node1 = headB;
            }
            if(node2){
                node2 = node2->next;
            }
            else{
                node2 = headA;
            }
        }
        return node1;
    }
};
```
3.带环的链表判断是否有交点
- [具体原理](https://www.cnblogs.com/mukekeheart/p/5664321.html)
- [另一篇](https://blog.csdn.net/gao1440156051/article/details/51689521)
+ 分析：如果有环且两个链表相交，则两个链表都有共同一个环，即环上的任意一个节点都存在于两个链表上。因此，就可以判断一链表上俩指针相遇的那个节点，在不在另一条链表上。
  - 无环链表和有环链表是不可能相交的;
  - 两个有环链表若相交，其“整个环上”的所有node一定都重合;
  - **有环链表的相交，交点只可能有2种情况：交点位于链表的”环上”或交点位于”不是环的部分”**
+ **有环单链表是否相交的判断方法：** 先比较两个链表的入环节点是否相等，若相等，则相交，若不相等，则从某个链表的入环节点开始循环一周，判断是否有节点等于另一个链表的入环节点，若等于，则相交，否则不相交。
+ 简单实现
```C++
//判断单链表是否存在环,参数circleNode是环内节点，后面的题目会用到
bool hasCircle(Node *head,Node *&circleNode)
{
    Node *slow,*fast;
    slow = fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            circleNode = fast;
            return true;
        }
    }
    return false;
//判断两个带环链表是否相交
bool isIntersectWithLoop(Node *h1,Node *h2)
{
    Node *circleNode1,*circleNode2;
    if(!hasCircle(h1,circleNode1))    //判断链表带不带环，并保存环内节点
        return false;                //不带环，异常退出
    if(!hasCircle(h2,circleNode2))
        return false;
 
    Node *temp = circleNode2->next;
    while(temp != circleNode2)
    {
        if(temp == circleNode1)
            return true;
        temp = temp->next;
    }
    return false;
```

## 在排序数组中查找数字I

1.题目
```
统计一个数字在排序数组中出现的次数。

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
```
2.实现
```C++
    // int search(vector<int>& nums, int target) {
    //     if(nums.size()==1) return nums[0]==target? 1:0;
    //     int left=0,right=nums.size()-1;
    //     int res = helper(nums,left,right,target)-helper(nums,left,right,target-1);
    //     return res;
    // }
    // int helper(vector<int>& nums, int left, int right, int target){
    //     while(left<=right){
    //         int mid = left + (right-left)/2;
    //         if(nums[mid]>target){
    //             right = right-1;
    //         }
    //         else{
    //             left = mid+1;
    //         }
    //     }
    //     return left;
    // }
        int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return 0;
        int left=0,right=len-1;
        int l,r;
        int res=0;
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        if(nums[left]!=target)return 0;
        l = left;
        right = len-1;
        while(left<right){
            int mid = (left+right+1)/2;
            if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid;
            }
        }
        r = left;
        return r-l+1;
    }
```
## 0到n-1中缺失的数字

1.题目
```
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8
```
2.实现
```C++
    // int missingNumber(vector<int>& nums) {
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i] != i) return i;
    //     }
    //     return nums.size();
    // }
        int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid] == mid){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
```
## 二叉搜索树的第k大节点

1.题目
```
给定一棵二叉搜索树，请找出其中第k大的节点。

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
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
    vector<int> res;
    int kthLargest(TreeNode* root, int k) {
        helper(root);
        int len = res.size();
        int ans = res[len-k];
        return ans;
    }
    void helper(TreeNode* root){
        if(root == NULL) return;
        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }
};
```
## 二叉树的深度
1.题目
```
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
```
2.分析
+ DFS回溯算法
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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
class Solution {
public:
    int res = 0;
    int maxDepth(TreeNode* root) {
        int ans = helper(root,0);
        return ans;
    }

    int helper(TreeNode* root,int depth){
        if(root == NULL) return depth;
        depth++;
        res = max(res,depth);
        helper(root->left,depth);
        helper(root->right,depth);
        depth--;
        return res;
    }
};
```
+ BFS算法
```C++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                TreeNode* node = q.front(); 
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans ++;
        }
        return ans;
    }
};
```
## 数组中数字出现的次数II

1.题目
```
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

输入：nums = [3,4,3,3]
输出：4
```
2.分析
+ 如果某个数字出现3次，那么这个3个数字的和肯定能被3整除，则其对应二进制位的每一位的和也能被3整除
+ 统计数组中每个数字的二进制中每一位的和，判断该和是否能被3整除。
+ 若可以，则只出现一次的数字的二进制数中那一位为0，否则为1
+ 实现
```C++
// 哈希表算法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int n : nums) mp[n] ++;
        int ans;
        for(auto pr : mp){
            if(pr.second == 1){
                ans = pr.first;
                break;
            }
        }
        return ans;
    }
};
// 位运算算法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            int cnt = 0;
            for(int n : nums){
                // n & 1 << i 的值大于0即为真
                if(n & (1 << i)) cnt++;
            }
            // 构造只出现一次的那个数字，采用异或的方法生成二进制中的每一位
            if(cnt % 3 == 1) ans ^= (1 << i);
        }
        return ans;
    }
};
```
## 和为s的两个数字

1.题目
```
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]
```
2.实现
```C++
//双指针算法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            if(nums[left]+nums[right]<target){
                left++;
            }
            else if(nums[left]+nums[right]>target){
                right--;
            }
            else{
                return {nums[left],nums[right]};
            }
        }
        return {};
    }
};
//hash表算法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numbers;
        for(int i = 0; i < nums.size(); i ++){
            numbers[nums[i]] = 1;
        }
        for(int i = 0; i < nums.size(); i ++){
            if(numbers[target - nums[i]]) 
                return {nums[i], target - nums[i]};
        }
        return {};
    }
};
```
## 翻转单词顺序

1.题目
```
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

输入: "the sky is blue"
输出: "blue is sky the"

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
```
2.实现
```C++
class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string res,str;
        istringstream ss(s);
        while (ss >> str){
            stk.push(str), stk.push(" ");
        }
        if (!stk.empty()) stk.pop();
        while (!stk.empty()) {
            res += stk.top(), stk.pop();
        }
        return res;
    }
};
```
## 左旋转字符串

1.题目
```
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

输入: s = "abcdefg", k = 2
输出: "cdefgab"
```
2.实现
```C++
//遍历法
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans = "";
        for (int i = n; i < s.size(); ++i)
            string += s[i];
        for (int i = 0; i < n; ++i)
            string += s[i];
        return ans;
    }
};
//切片法（经典）
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return (s + s).substr(n, s.size());
    }
};
//使用substr的切片法
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans;
        int len = s.size();
        if(len == 0) return "";
        if(len == 1) return s;
        ans = s.substr(n,len-n) + s.substr(0,n);
        return ans;
    }
};
//要求不使用额外空间的原地翻转
class Solution {
public:
    string reverse(string &s,int i,int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    string reverseLeftWords(string s, int n) {
        int size = (int)s.size();
        if (size <= 1) return s;
        reverse(s, 0, n-1);
        reverse(s, n, size-1);
        reverse(s, 0, size-1);
        return s;
    }
};
```
## 滑动窗口的最大值

1.题目
```
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 
  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```
2.分析

+ [这篇对于单调队列的分析很好](https://leetcode-cn.com/problems/sliding-window-maximum/solution/dan-diao-dui-lie-by-labuladong/)
+ 实现
```C++
// 优先队列做法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> que;
        for (int i = 0; i < nums.size(); ++i) {
            que.push({nums[i], i});
            if (i >= k - 1) {
                while (que.top().second < i - k + 1) que.pop();
                ans.push_back(que.top().first);
            } 
        }
        return ans;
    }
};

//单调队列解法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (! que.empty() && que.front() == i - k) que.pop_front();
            while (! que.empty() && nums[i] >= nums[que.back()]) que.pop_back();
            que.push_back(i);
            if (i >= k - 1) ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};

//单调栈封装成类的实现
class MonotonicQueue {
private:
    deque<int> data;
public:
    void push(int n) {
        while (!data.empty() && data.back() < n) 
            data.pop_back();
        data.push_back(n);
    }
    
    int max() { return data.front(); }
    
    void pop(int n) {
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) { //先填满窗口的前 k - 1
            window.push(nums[i]);
        } else { // 窗口向前滑动
            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i - k + 1]);
        }
    }
    return res;
}
```
## 队列的最大值

1.题目
```
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
```
2.分析
+ [官方解答很好](https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/)
+ 从队列尾部插入元素时，我们可以提前取出队列中所有比这个元素小的元素，使得队列中只保留对结果有影响的数字。这样的方法等价于要求维持队列单调递减，即要保证每个元素的前面都没有比它小的元素。
+ 那么如何高效实现一个始终递减的队列呢？我们只需要在插入每一个元素 value 时，从队列尾部依次取出比当前元素 value 小的元素，直到遇到一个比当前元素大的元素 value' 即可。
  - 上面的过程保证了只要在元素 value 被插入之前队列递减，那么在 value 被插入之后队列依然递减。
  - 而队列的初始状态（空队列）符合单调递减的定义。
  - 由数学归纳法可知队列将会始终保持单调递减。
+ 上面的过程需要从队列尾部取出元素，因此需要使用双端队列来实现。另外我们也需要一个辅助队列来记录所有被插入的值，以确定 pop_front 函数的返回值。
+ 实现
```C++
class MaxQueue {
    queue<int> every_num;
    deque<int> max_num;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (every_num.empty())
            return -1;
        return max_num.front();
    }
    
    void push_back(int value) {
        while (!max_num.empty() && max_num.back() < value) {
            max_num.pop_back();
        }
        max_num.push_back(value);
        every_num.push(value);
    }
    
    int pop_front() {
        if (every_num.empty())
            return -1;
        int ans = every_num.front();
        if (ans == max_num.front()) {
            max_num.pop_front();
        }
        every_num.pop();
        return ans;
    }
};
/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```
## n个骰子的点数

1.题目
```
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
```
2.分析
+ 很典型的背包问题
+ [具体见这篇分析](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/nge-tou-zi-de-dian-shu-dong-tai-gui-hua-ji-qi-yo-3/)
+ 两种实现
```C++
class Solution {
public:
    vector<double> twoSum(int n) {
        int all_times = pow(6,n);
        //dp[i][j]表示扔i个骰子点数之和为j出现的次数(假设扔6^n次，每种情况出现一次)
        vector<vector<int>> dp(15,vector<int>(70,0));
        vector<double> ans;
        for(int i=1;i<=6;i++){
            dp[1][i] = 1;
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j<=6*i;j++){
                for(int cur=1;cur<=6;cur++){
                    if(j-cur<=0) break;
                    dp[i][j] += dp[i-1][j-cur];
                }
            }
        }
        for(int i=n;i<=6*n;i++){
            ans.push_back((1.0*dp[n][i])/all_times);
        }
        return ans;
    }
};

//优化空间后的一维数组
class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[70];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; i ++) {
            dp[i] = 1;
        }
        for (int i = 2; i <= n; i ++) {
            for (int j = 6*i; j >= i; j --) {
                dp[j] = 0;
                for (int cur = 1; cur <= 6; cur ++) {
                    if (j - cur < i-1) {
                        break;
                    }
                    dp[j] += dp[j-cur];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ret;
        for (int i = n; i <= 6 * n; i ++) {
            ret.push_back(dp[i] * 1.0 / all);
        }
        return ret;
    }
};
```
## 扑克牌中的顺子

1.题目
```
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

输入: [1,2,3,4,5]
输出: True

输入: [0,0,1,2,5]
输出: True
```
2.分析
+ [数学思想见解析](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/solution/mian-shi-ti-61-bu-ke-pai-zhong-de-shun-zi-ji-he-se/)
+ 根据题意，此 55 张牌是顺子的 充分条件 如下：
  - 除大小王外，所有牌无重复 ；
  - 设此 5 张牌中最大的牌为 max ，最小的牌为 min （大小王除外），则需满足：max - min < 5
+ 实现
```C++
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> res;
        int min_num = 14;
        int max_num = 0;
        for(auto num:nums){
            if(num == 0) continue;
            if(res.count(num)) return false;
            max_num = max(max_num,num);
            min_num = min(min_num,num);
            res.insert(num);
        }
        if(max_num-min_num<5){
            return true;
        }
        else{
            return false;
        }
    }
};
```
## 圆圈中最后剩下的数字

1.题目
```
0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

输入: n = 5, m = 3
输出: 3
```
2.分析
+ [这篇讲解很好](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/javajie-jue-yue-se-fu-huan-wen-ti-gao-su-ni-wei-sh/)
+ 实现
```C++
//环形链表法，算法超时
class Solution {
public:
    int lastRemaining(int n, int m) {
        list<int> nums;
        int res;
        for(int i=0;i<n;i++){
            nums.push_back(i);
        }
        list<int>::iterator cur = nums.begin();
        while(!nums.empty()){
            for(int i=1;i<m;i++){
                cur++;
                if(cur == nums.end()){
                    cur = nums.begin();
                }
            }
            res = *cur;//把所有元素放到链表中，一个个走，然后删除。直到删除完为止，拿到最后一个删除的元素
            cur = nums.erase(cur); // list erase 操作返回后序的迭代器
            if(cur == nums.end()){
                cur = nums.begin();
            }
        }
        return res;
    }
};

//数学算法实现
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ret = 0;
        for (int i = 2; i <= n; i++) {
            ret = (ret + m) % i;
        }
        return ret;
    }
};
```
## 不用加减乘除做加法

1.题目
```
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
```
2.分析
+ LeetCode c++ 不允许负数左移操作，所以**要转换成无符号整数**
+ 书中的说法比较清晰
+ 实现
```C++
/*
 * 位运算
 *
 * 因为不能使用加减乘除四则运算，所以只能想到使用二进制的位运算实现相加操作。
 * 二进制位运算中，异或操作: 1^1=0 0^0=0 1^0=1 0^1=1，可以模拟无进位的加操作；
 * 与操作：1&1=1 0&1=0 1&0=0 0&0=0，可以模拟进位的情况，再将与后的值左移一位即等于进位值。
 *
 * 普通的十进制数相加过程是：
 * 1) 各位相加，无进位和 2) 计算进位值 3) 无进位和加上进位值
 *
 * 使用位运算的二进制数的相加过程相同：
 * 1) 两个二进制数各位异或，得到无进位的和 2) 二进制数各位与再左移，计算进位 3) 无进位和与进位异或
 * 重复上面操作，直到不再有进位，即进位为0。
 *
 * 相关问题：
 * 不使用新的变量，交换两个变量的值。比如有两个变量a、b，希望交换它们的值。有两种不同的操作：
 * 1. 基于加减法 -- a = a + b; b = a - b; a = a - b;
 * 2. 基于位运算 -- a = a ^ b; b = a ^ b; a = a ^ b;
 * */
int add(int a, int b) {
    // 无进位和、进位值
    int sum, carry;
    while (b != 0) {
        // 异或操作得无进位和
        sum = a ^ b;
        // 与操作后移位得进位值
        carry = ((unsigned int) (a & b) << 1);

        // 循环，直到进位为0
        a = sum;
        b = carry;
    }
    return a;
}
```
## 构建乘积数组

1.题目
```
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
```
2.分析
+ 实现（直接看代码）
```C++
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if(len==1 || len==0) return a;
        vector<int> ans(len);
        ans[0] = 1;
        for(int i=1;i<len;i++){
            ans[i] = ans[i-1]*a[i-1];
        }
        int right=1;
        for(int i=len-2;i>=0;i--){
            right = right*a[i+1];
            ans[i] = ans[i]*right;
        }
        return ans;
    }
};
```
## 把字符串转换成整数

1.题目
```
写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
```
2.分析
```C++
class Solution {
public:
    int strToInt(string str) {
        int i = 0, flag = 1;
        long res = 0; //默认flag = 1，正数
        while (str[i] == ' ') i ++;
        if (str[i] == '-') flag = -1;
        if (str[i] == '-' || str[i] == '+') i ++;
        for (; i < str.size() && isdigit(str[i]); i ++)  {
            res = res * 10 + (str[i] - '0');
            if (res >= INT_MAX && flag == 1) return  INT_MAX;
            if (res > INT_MAX && flag == -1) return  INT_MIN;
        } 
        return flag * res;
    }
};

class Solution {
public:
    int myAtoi(string str) {
       int num=0;
    istringstream str_1(str);
    //while (num==0)
        str_1 >> num;
    if (num > INT_MAX)
        return INT_MAX;
    else if (num < INT_MIN)
        return INT_MIN;
    else
        return num;
    }
};
```
##  二叉搜索树的最近公共祖先
1.题目
```
建议看原题题目

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。
```
2.分析
+ 由于是二叉搜索树，那么边界条件就是，p、q 分别在 root 的两边(一个大于root一个小于root)，或者 p、q 等于 root，那么 root 就是 p、q 的公共祖先。
+ 当 p、q 都小于 root，根据二叉搜索树的特征，那么 p、q 的祖先一定在 root 的左子树上，所以接下来遍历左子树就行。
+ 同理，当 p、q 都大于 root，只需要遍历 root 的右子树即可。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || (root->left == NULL && root->right == NULL))return NULL;
        while(root) {
            if((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val) || root->val == p->val || root->val == q->val) return root;

            if(root->val > p->val && root->val > q->val) root = root->left;
            if(root->val < p->val && root->val < q->val) root = root->right;
        }
        return root;
    }
};
```
## 二叉树的最近公共祖先

1.题目
```
建议看原题目
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
```
2.分析
+ 两种实现方法
```C++
//方法一
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL||root->val == p->val||root->val == q->val) return root;//立即返回或终止的条件
        TreeNode* left = lowestCommonAncestor(root->left,p,q);//递归左子树
        TreeNode* right = lowestCommonAncestor(root->right,p,q);//递归右子树
        if(left == NULL&&right == NULL) return NULL;//返回情况1
        if(left == NULL) return right;//返回情况3
        if(right == NULL) return left;//返回情况4
        return root;//返回情况2
    }
//方法二
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root){//算是后序遍历，并记录父节点吧
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {//从p开始往上找父节点（父节点、父节点的父节点....）
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {//把q找的父节点与p的作对比，一直对比，直到找到公共祖先
            if (vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }
```
## 股票的最大利润

1.题目
```
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
```
2.分析
+ [建议看解析](https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E5%9B%A2%E7%81%AD%E8%82%A1%E7%A5%A8%E9%97%AE%E9%A2%98.md)
+ 实现
```C++
class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int len = prices.size();
    //     if(len == 0||len == 1) return 0;
    //     vector<vector<int>> dp(len,vector<int>(2));
    //     dp[0][0] = 0;
    //     dp[0][1] = -prices[0];
    //     for(int i=1;i<len;i++){
    //         dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
    //         dp[i][1] = max(dp[i-1][1],-prices[i]);
    //     }
    //     return dp[len-1][0];
    // }
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0||len == 1) return 0;
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for(int i=1;i<len;i++){
            dp_i_0 = max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1 = max(dp_i_1,-prices[i]);
        }
        return dp_i_0;
    }
};
```
## 字符串的排列
1.题目
```
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
```
2.实现
```C++
class Solution {
public:
     vector<string> permutation(string s) {
        vector<string> result;//最终输出结果
        set<string> res;//使用set的性质去除重复字符串排列
        if(s == "" || s.length()== 1 ){
            result.push_back(s);
            return result;
        }
        paixu(s,0,res);//回溯算法，递归函数（路径+可选择列表）
        result = vector<string>(res.begin(),res.end());
        return result;
    }
    void paixu(string s,int start, set<string> &res){
        if(start == s.size()){
            res.insert(s);//注意这里不能用push_back
            return;//虽然是void类型，return不要忘记
        }
        for(int i = start; i<s.size(); i++){
            swap(s[i],s[start]);
            paixu(s,start+1,res);
            swap(s[i],s[start]);
        }
    }
};
```
## 数组中的逆序对
1.题目
```
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

输入: [7,5,6,4]
输出: 5
```
2.实现
```C++
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};
```
## 求1+...+n
1.题目
```
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

输入: n = 3
输出: 6
```
2.实现
```C++
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n;
    }
};
```
## 二叉树的最大路径和
1.题目
```
给定一个非空二叉树，返回其最大路径和。
本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
输入: [1,2,3]

       1
      / \
     2   3

输出: 6
```
2.分析
+ 本题目涉及带参数的递归调用（DFS）
+ 递归思想直接看代码
```C++
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int res = INT_MIN;//现将值设为允许的最小值（万一树节点里面全是负的）。
        dfs(root,res);//直接调用递归函数，只需要确定res，不需要使用返回值。
        return res;
    }
    int dfs(TreeNode* root,int& res){
        if(root == NULL){//DFS遍历到最底层时返回
            return 0;
        }
        int left = max(0,dfs(root->left,res));//确定当前访问节点的左子树的最大路径和
        //注意要和0比较，因为如果小于0我们可以不选择这一条路径，也就是左子树路径为0.
        int right = max(0,dfs(root->right,res));//确定当前访问节点的右子树的最大路径和
        res = max(res,root->val+right+left);//更新最大路径和，因为是当前节点的最大路径和，一定要包括当前节点
        return root->val+max(right,left);//返回时要因为时返回一条路径，
        //所以只能是当前节点和左/右子树选一条路径和大的返回
    }
};
```
## 环形链表
1.题目
```
给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```
2.分析
+ [这篇解析很好](https://leetcode-cn.com/problems/linked-list-cycle/solution/yi-wen-gao-ding-chang-jian-de-lian-biao-wen-ti-h-2/)
+ [如何判断是否是环形链表、环形长度、入口节点的分析文章](https://blog.csdn.net/qq_40965479/article/details/106299007)

3. 判断是否是环形链表
+ 首先创建两个对象fast和slow，让它们同时指向这个链表的头节点
+ 然后开始一个大循环，在循环体中，让对象slow每次向后移动1个节点，让对象fast每次向后移动2个节点
+ 比较两个指针指向的节点是否相同。如果相同，则可以判断出链表有环，如果不同，则继续下一次循环
+ 实现
```C++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr) {
            fast = fast->next;
            if(fast != nullptr) {
                fast = fast->next;
            }
            if(fast == slow) {
                return true;
            }
            slow = slow->next;
        }
        return nullptr;
    }
};
```
4.判断环的位置
+ 快慢指针相遇后，把其中一个指针放回到头节点位置， 另一个指针保持在首次相遇点
+ 两个指针都是每次向前走1步。
+ 那么，它们最终相遇的节点，就是入环节点。
+ 实现
```C++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
```
5.计算环形链表长度
+ 当两个指针首次相遇，证明链表有环的时候
  - 让两个指针从相遇点继续循环前进，并统计前进的循环次数，直到两个指针第2次相遇。
  - 此时，统计出来的前进次数就是环长。
+ 因为指针slow每次走1步，指针fast每次走2步，两者的速度差是1步。 当两个指针再次相遇时，fast比slow多走了整整1圈
+ 环长 = 每一次速度差 × 前进次数 = 前进次数
+ 实现
```java
/**
 * 环形链表的长度
 *
 * @param p1 每次移动1格
 * @param p2 每次移动2格
 * @return
 */
public static void nodeLength(Node p1, Node p2) {
    int temp = 0;
    do {
        p2 = p2.next;
        temp++;
    }
    while (p1 != p2);
    System.out.println("环形链表长度 = " + temp);
}
```


## 合并k个排序链表
1.题目
```
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:
输入:
[ 1->4->5,
  1->3->4,
  2->6 ]
输出: 1->1->2->3->4->4->5->6
```
2.实现
```C++
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};
struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

ListNode* sortList(ListNode* head)
{
    if(!head)
        return head;
    ListNode *pre, *q = head->next, *t;
    ListNode* h = new ListNode(-1);
    h->next = head;
    head->next = nullptr;
    while(q){
        for(pre = h; pre->next && q->val >= pre->next->val; pre = pre->next);
        t = q->next;
        q->next = pre->next;
        pre->next = q;
        q = t;
    }
    return h->next;
}


ListNode* mergeLists(vector<ListNode*>& lists){

    priority_queue<ListNode*,vector<ListNode*>,cmp> pri;
    for(auto elem:lists){
        if(elem) {
            pri.push(elem);
        }
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* res = dummy;
    while(!pri.empty()){
        ListNode* top = pri.top();
        pri.pop();
        res->next = top;
        res = res->next;
        if(res->next){
            pri.push(top->next);
        }
    }
    return dummy->next;// write your code here
};
int main(){
    int n = 0;
    cin >> n;
    vector<ListNode*> lists(n);
    for(int i = 0; i < n; i++){
        int num;
        ListNode* head = new ListNode(-1);
        ListNode* res = head;
        while(cin>>num){
            ListNode* mem = new ListNode(num);
            res->next = mem;
            res = res->next;
            if(getchar() == '\n') break;
        }// write your code here
        ListNode* list = sortList(head->next);
        lists.push_back(list);
    }

    ListNode* ans = mergeLists(lists);
    while(ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }// output nodes

    return 0;
}

```
## 链表排序
1.题目
```
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

输入: 4->2->1->3
输出: 1->2->3->4

输入: -1->5->3->4->0
输出: -1->0->3->4->5
```
2.实现
```C++
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* pmid;
        ListNode* mid = head;
        ListNode* trail = head;
        while (trail && trail->next)
        {
            pmid = mid;
            mid = mid->next;
            trail = trail->next->next;
        }
        pmid->next = NULL;

        return twoWayMerge(sortList(head), sortList(mid));
    }

    ListNode* twoWayMerge(ListNode* l1, ListNode* l2) {
        ListNode header(-1);
        ListNode *p = &header;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        p->next = l1 == NULL ? l2 : l1;

        return header.next;
    }
};
```
## 二叉树的最长同值路径
1.题目
```
定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
注意：两个节点之间的路径长度由它们之间的边数表示。

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:
2
```
2.实现
```C++
int help(TreeNode* node, int &ans) {
    if (node == nullptr) return 0;

    int left = help(node->left, ans);
    int right = help(node->right, ans);

    left = (node->left != nullptr && node->val == node->left->val) ? left + 1 : 0;
    right = (node->right != nullptr && node->val == node->right->val) ? right + 1 : 0;

    ans = max(ans, left + right);
    return max(left, right);
}

int longestUnivaluePath(TreeNode* root) {
    int ans = 0;
    help(root, ans);
    return ans;
}
```
## 最长递增子序列
1.题目
```
给定一个无序的整数数组，找到其中最长上升子序列的长度。

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
```
2.实现
+ 定义：dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度，这样设计可能算法上有点重叠，但是比较简练，且每个子问题肯定是最优解。
+ 状态转移：例如nums={1,4,3,4,2,3}，假设已知dp[0]~dp[4] 类似数学归纳法,求dp[5]。既然是递增子序列，nums[5]=3,我们只要找到前面那些结尾比 3 小的子序列，然后把 3 接到最后，就可以形成一个新的递增子序列，而且这个新的子序列长度加1。
+ 实现：
```C++
//动态规划版本
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return 1;

        vector<int> dp(n,1);
        int res=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
//优化版本
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> dp(len + 1, 0);
        dp[1] = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i] > dp[ans]){
                ans++;
                dp[ans] = nums[i];
            } 
            else{
                int left = 1, right = ans, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (left <= right) {
                    int mid = (left + right)/2;
                    if (dp[mid] < nums[i]) {
                        pos = mid;
                        left = mid + 1;
                    }
                    else right = mid - 1;
                }
                dp[pos + 1] = nums[i];
            }
        }
        return ans;
    }
};
```
## 最大连续1的个数III
1.题目
```
给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
返回仅包含 1 的最长（连续）子数组的长度。

输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释： 
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。

输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
```
2.实现
```C++
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        //count用来统计窗口中0的个数
        int left=0;
        int right=0;
        int count=0;
        int result=0;
        while(right<A.size())
        {
            if(A[right] == 0){
                count++;
            }
            while(count>K)//当窗口内0的个数大于K时，需要缩小窗口
            {
                if(A[left] == 0){
                    count--;
                }
                left++;
            }
            //窗口内0的个数小于等于k时，也就是可以该窗口内的0都可以替换，根据该窗口长度来确定是否更新result
            result=max(result,right-left+1);
            right++;
        }
        return result;
    }
};
```
## 爬楼梯问题
1.题目
```
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
```
2.实现
```C++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2;i<n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};
class Solution {
public:
    int numWays(int n) {
        if(n==0 || n==1) return 1;
        int a = 1;
        int b = 1;
        for(int i=2;i<=n;i++){
            int sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return b;
    }
};
```
## 鸡蛋掉落
1.题目
```
你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
你的目标是确切地知道 F 的值是多少。
无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

输入：K = 1, N = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
如果它没碎，那么我们肯定知道 F = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
```
2.分析
+ 对动态规划问题，直接套框架即可：这个问题有什么「状态」，有什么「选择」，然后穷举。
+ 「状态」很明显，就是当前拥有的鸡蛋数 K 和需要测试的楼层数 N。随着测试的进行，鸡蛋个数可能减少，楼层的搜索范围会减小，这就是状态的变化。
+ 「选择」其实就是去选择哪层楼扔鸡蛋。线性扫描选择一层层向上测试。不同的选择会造成状态的转移。
+ 明确了「状态」和「选择」，动态规划的基本思路就形成了：肯定是个二维的 dp 数组或者带有两个状态参数的 dp 函数来表示状态转移；外加一个 for 循环来遍历所有选择，择最优的选择更新状态：
+ 实现
```C++
class Solution {
    unordered_map<int, int> memo;
    int dp(int K, int N) {
        if (memo.find(N * 100 + K) == memo.end()) {
            int ans;
            if (N == 0) ans = 0;
            else if (K == 1) ans = N;
            else {
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K-1, x-1);
                    int t2 = dp(K, N-x);

                    if (t1 < t2) lo = x;
                    else if (t1 > t2) hi = x;
                    else lo = hi = x;
                }

                ans = 1 + min(max(dp(K-1, lo-1), dp(K, N-lo)),
                                   max(dp(K-1, hi-1), dp(K, N-hi)));
            }

            memo[N * 100 + K] = ans;
        }

        return memo[N * 100 + K];
    }
public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
};
```
## 三数之和
1.题目
```
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```
2.实现
```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len<=2) return {};
        set<vector<int>> ans;
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            if(nums[i]>0) break;
            int left = i+1;
            int right = len-1;
            while(left<right){
                if(nums[left]+nums[right] == -nums[i]){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.insert(temp);
                    temp.clear();
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right]< -nums[i]){
                    left++;
                }
                else{
                    right--;
                }
            }
            
        }
        res.assign(ans.begin(),ans.end());
        return res;
    }
};
```
## 最长公共子序列

1.题目要求
```
输入: str1 = "abcde", str2 = "ace" 
输出: 3  
解释: 最长公共子序列是 "ace"，它的长度是 3
```

2.**一道典型的动态规划题目**

[!具体解答看这篇文章](https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97.md)

3.最长公共子序列（Longest Common Subsequence，简称 LCS）是一道非常经典的面试题目，因为它的解法是典型的二维动态规划，大部分比较困难的字符串问题都和这个问题一个套路，比如说No.72 编辑距离。而且，这个算法稍加改造就可以用于解决其他问题，所以说 LCS 算法是值得掌握的。

4.**第一步**，一定要明确**dp 数组的含义**。对于两个字符串的动态规划问题，套路是通用的。比如说对于字符串 s1 和 s2，一般来说都要构造一个这样的 DP table.

**第二步**，定义 base case。我们专门让索引为 0 的行和列表示空串，dp[0][..] 和 dp[..][0] 都应该初始化为 0，这就是 base case。

比如说，按照刚才 dp 数组的定义，dp[0][3]=0 的含义是：对于字符串 "" 和 "bab"，其 LCS 的长度为 0。因为有一个字符串是空串，它们的最长公共子序列的长度显然应该是 0。

**第三步**，找状态转移方程。这是动态规划最难的一步，不过好在这种字符串问题的套路都差不多，权且借这道题来聊聊处理这类问题的思路。

状态转移说简单些就是做选择，比如说这个问题，是求 s1 和 s2 的最长公共子序列，不妨称这个子序列为 lcs。那么对于 s1 和 s2 中的每个字符，有什么选择？很简单，两种选择，要么在 lcs 中，要么不在。还是看代码最直观：
```C++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.length();
        int length2 = text2.length();
        //构建 DP table 和 base case
        vector<vector<int>> dp(length1+1,vector<int>(length2+1));
        for(int i = 0;i<length1+1;i++){
            dp[i][0] = 0;
        }
        for(int i = 0;i<length2+1;i++){
            dp[0][i] = 0;
        }
        if(length1 == 0 || length2 == 0){
            return 0;
        }
        //进行状态转移
        for(int i = 1;i<length1+1;i++ ){
            for(int j =1;j<length2+1;j++){
                if(text1[i-1] == text2[j-1]){//找到一个 lcs 中的字符
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[length1][length2];
    }
};
```
## 二叉树展开为链表

1.题目
```
给定一个二叉树，原地将它展开为一个单链表。
例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
```
2.分析
- 前序遍历方法
```C++
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        vector<TreeNode*> memo;
        Forward_vist(root,memo);
        int length = memo.size();
        for(int i=0;i<memo.size()-1;i++){
            memo[i]->left = nullptr;
            memo[i]->right = memo[i+1];
        }
        memo[length-1]->left = nullptr;
        memo[length-1]->right = nullptr;
    }
    void Forward_vist(TreeNode* root, vector<TreeNode*>& memo){
        if(root == nullptr){
            return;
        }
        memo.push_back(root);
        Forward_vist(root->left,memo);
        Forward_vist(root->right,memo);
    }
};
```
- 三指针原地翻转
  - [方法3解析图解比较好](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/)
  - 注意到前序遍历访问各节点的顺序是根节点、左子树、右子树。如果一个节点的左子节点为空，则该节点不需要进行展开操作。如果一个节点的左子节点不为空，则该节点的左子树中的最后一个节点被访问之后，该节点的右子节点被访问。该节点的左子树中最后一个被访问的节点是左子树中的最右边的节点，也是该节点的前驱节点。因此，问题转化成寻找当前节点的前驱节点。
  - 具体做法是，对于当前节点，如果其左子节点不为空，则在其左子树中找到最右边的节点，作为前驱节点，将当前节点的右子节点赋给前驱节点的右子节点，然后将当前节点的左子节点赋给当前节点的右子节点，并将当前节点的左子节点设为空。对当前节点处理结束后，继续处理链表中的下一个节点，直到所有节点都处理结束。
  - 实现
```C++
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode* cur = root;
        while(cur){
            if(cur->left){
                TreeNode* next = cur->left;
                TreeNode* most_right = next;
                while(most_right->right){
                    most_right = most_right->right;
                }
                most_right->right = cur->right;
                cur->left = nullptr;
                cur->right = next;
            }
            cur = cur->right;
        }
    }   
};
```
## 字符串相加
1.题目
```
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
```
2.实现
+ 我们定义两个指针 i 和 j 分别指向 num1 和 num2 的末尾，即最低位，同时定义一个变量 add 维护当前是否有进位，然后从末尾到开头逐位相加即可。你可能会想两个数字位数不同怎么处理，这里我们统一在指针当前下标处于负数的时候返回 0，等价于对位数较短的数字进行了补零操作，这样就可以除去两个数字位数不同情况的处理，具体可以看下面的代码。
```C++
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int add = 0;
        int i = num1.size()-1;
        int j = num2.size()-1;
        while(i>=0 || j>=0 || add != 0){//add != 0这个判断你很关键，用来保证最高位进1也可以工作！
            int a = 0,b = 0;
            if(i>=0){
                a = num1[i] - '0';
            }
            if(j>=0){
                b = num2[j] - '0';
            }
            int result = a + b + add; 
            add = result/10;
            ans.push_back(result%10+'0');
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
## LRU缓存机制
1.题目
```
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

RUCache cache = new LRUCache( 2 /* 缓存容量 */ );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
```
2.分析
+ LRU 缓存机制可以通过哈希表辅以双向链表实现，我们用一个哈希表和一个双向链表维护所有在缓存中的键值对。
  - 双向链表按照被使用的顺序存储了这些键值对，靠近头部的键值对是最近使用的，而靠近尾部的键值对是最久未使用的。
  - 哈希表即为普通的哈希映射（HashMap），通过缓存数据的键映射到其在双向链表中的位置。
+ 对于 get 操作，首先判断 key 是否存在：
  - 如果 key 不存在，则返回 -1；
  - 如果 key 存在，则 key 对应的节点是最近被使用的节点。通过哈希表定位到该节点在双向链表中的位置，并将其移动到双向链表的头部，最后返回该节点的值。
+ 对于 put 操作，首先判断 key 是否存在：
  - 如果 key 不存在，使用 key 和 value 创建一个新的节点，在双向链表的头部添加该节点，并将 key 和该节点添加进哈希表中。然后判断双向链表的节点数是否超出容量，如果超出容量，则删除双向链表的尾部节点，并删除哈希表中对应的项；
  - 如果 key 存在，则与 get 操作类似，先通过哈希表定位，再将对应的节点的值更新为 value，并将该节点移到双向链表的头部。
+ **在双向链表的实现中，使用一个伪头部（dummy head）和伪尾部（dummy tail）标记界限，这样在添加节点和删除节点的时候就不需要检查相邻的节点是否存在。**

3.实现
```C++
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
```
## 旋转链表

1.题目
```
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
```
2.分析
![image](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/images/%E6%97%8B%E8%BD%AC%E9%93%BE%E8%A1%A8.png)

3.实现
```C++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int n=0;
        for(auto p=head;p;p=p->next) n++;
        k%=n;
        auto first=head,second=head;
        while(k--){
            first=first->next;
        }
        while(first->next){
            first=first->next;
            second=second->next;
        }
        first->next=head;
        head=second->next;
        second->next=NULL;
        return head;
    }
};
``` 
## 字符串相减

```C++
#include <iostream>
#include <sstream>
using namespace std;
string Subtraction(string num1,string num2)
{
    //fushu用来判断最后结果是否是负数
    bool fushu = false;
    //如果被减数位数小于减数，那么结果是负数，同时两个字符串交换顺序，大的数减小的数
    if(num1.size()<num2.size())
    {
        string temp = num1;
        num1 = num2;
        num2 = temp;
        fushu = true;
    }
    //两个数长度一样，这个时候，需要判断哪个数更大，如果被减数小于减数，那么结果是负数，同时两个字符串交换顺序，大的数减小的数
    else if(num1.size() == num2.size())
    {
        int len = num1.size();
        for(int i=0;i<len;++i)
        {
            if(num1[i] == num2[i])
                continue;
            if(num1[i]>num2[i])
                break;
            if(num1[i]<num2[i])
            {
                string temp = num1;
                num1 = num2;
                num2 = temp;
                fushu = true;
            }
        }
    }
    int lenNum1 = num1.size();
    int lenNum2 = num2.size();

    //用来保存结果
    int* result = new int[lenNum1];
    int index = 0;
    //num1 31 num2 29 result 1,3
    //把被除数的结果先放到result中
    for(int i=lenNum1-1;i >=0;--i)
        result[index++]=num1[i]-'0';

    //进行减法操作
    index = 0;
    for(int i=lenNum2-1;i>=0;--i)
    {
        int num = num2[i]-'0';
        //如果减数 大于 被减数，则需要退位
        if(num>result[index])
        {
            result[index+1] -=1;
            result[index] = 10+result[index] - num;
        }
        //直接相减
        else
            result[index] = result[index] - num;

        ++index;
    }
    //清除result尾部的0,index从右到左遍历，直到第一个不是0为止
    index = lenNum1-1;
    while(result[index] == 0)
        --index;


    //使用stringstream流，方便把数组输出到字符串中
    ostringstream osstr;
    //判断是否结果是负数
    if(fushu == true)
        osstr<<'-';
    for(int i=index;i>=0;--i)
        osstr<<result[i];
    delete result;
    return osstr.str();
}
int main()
{

    string num1,num2;
    cin>>num1>>num2;
    cout<<Subtraction(num1,num2)<<endl;
    return 0;
}
```
## 字符串相乘
1.分析
- 把两个数用数组 a, b 来存储，并且反转（从个位开始乘）
- 对于 a 的第 i 位 和 b 的第 j 位相乘的结果存储在 c[i + j] 上，即 c[i + j] += a[i] * b[j];
这里用加号是因为有多种情况都会映射到 i + j 位上。
-  最后，从 c 的低位向高位整理，c[i + 1] = c[i] / 10, c[i] %= 10;

```
                            1   2   3
                        乘  4   5   6
                    ————————————————————
                            6   12  18
                        5   10  15
                    4   8   12
                    ————————————————————
                    4   13  28  27  18
                    整理： c[i + 1] += c[i] / 10, c[i] %= 10, 从低位开始。
                    step 0: 4   13  28  27  18
                    step 1: 4   13  28  28  8
                    step 2: 4   13  30  8   8
                    step 3: 4   16  0   8   8
                    step 4: 5   6   0   8   8
```

2.实现
```C++
class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        vector<int> a, b, c;
        c.resize(num1.size() + num2.size() - 1);
	//转成int类型主要是为了之后相乘（字符不能相乘），顺便把数字反转
        for (int i = num1.size() - 1; i >= 0; i--) a.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; i--) b.push_back(num2[i] - '0');
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        int k = 0;
        for (int i = 0; i < c.size(); i++) {
            k += c[i];
            char c = k % 10 + '0';
            ans = c + ans;
            k /= 10;
        }
        while (k) {
            char c = k % 10 + '0';
            ans = c + ans;
            k /= 10;
        }
        while (ans.size() > 1 && ans[0] == '0') ans.erase(ans.begin());
        return ans;
    }
};
```
## 两数相除

```
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign;
        if( (dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0) ){
            sign = 0;//两数同号，最终结果为正
        }else{
            sign = 1;//被除数和除数异号，最终结果为负数
        }
        long a = abs(dividend), cmp = abs(divisor);
        long res = 0, partial_sum = 1;
        int abs_divisor = cmp;//abs为除数绝对值的备份
        if(a < cmp) return 0;
	//通过移位，每次对除数乘2，使其快速逼近被除数（注意判断条件，最后cmp一定比a小）
        while((cmp << 1) < a){
            cmp = cmp << 1;
            partial_sum = partial_sum << 1;
        }
	//通过减法，将被除数减去partial_num倍的除数。
        while(a >= abs_divisor){
            a -= cmp;
            res += partial_sum;
            //cout << "a: " << a << " cmp: " << cmp << " partial_sum: " << partial_sum << endl;
            while(cmp > a){
                cmp = cmp >> 1;
                partial_sum = partial_sum >> 1;
            }
        }
	//根据sign标志将结果变为正数或负数
        if(sign == 1){
            if(-res < INT_MIN) return INT_MAX;
            else return -res;
        }else{
            if(res > INT_MAX) return INT_MAX;
            else return res;
        }
    }

};
```
## 最小覆盖子串
1.题目
```
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
```
2.分析
+ 我们可以用滑动窗口的思想解决这个问题，在滑动窗口类型的问题中都会有两个指针。一个用于「延伸」现有窗口的 r 指针，和一个用于「收缩」窗口的 l 指针。在任意时刻，只有一个指针运动，而另一个保持静止。我们在 s 上滑动窗口，通过移动 r 指针不断扩张窗口。当窗口包含 t 全部所需的字符后，如果能收缩，我们就收缩窗口直到得到最小窗口。
+ 用一个哈希表表示 t 中所有的字符以及它们的个数，用一个哈希表动态维护窗口中所有的字符以及它们的个数，如果这个动态表中包含 t 的哈希表中的所有字符，并且对应的个数都不小于 t 的哈希表中各个字符的个数，那么当前的窗口是「可行」的。
+ 实现：
```C++
//方法一：
string minWindow(string s, string t) {
    // 记录最短子串的开始位置和长度
    int start = 0, minLen = INT_MAX;
    int left = 0, right = 0;
    
    unordered_map<char, int> window;
    unordered_map<char, int> needs;
    for (char c : t) needs[c]++;
    
    int match = 0;
    
    while (right < s.size()) {
        char c1 = s[right];
        if (needs.count(c1)) {
            window[c1]++;
            if (window[c1] == needs[c1]) 
                match++;
        }
        right++;
        
        while (match == needs.size()) {
            if (right - left < minLen) {
                // 更新最小子串的位置和长度
                start = left;
                minLen = right - left;
            }
            char c2 = s[left];
            if (needs.count(c2)) {
                window[c2]--;
                if (window[c2] < needs[c2])
                    match--;
            }
            left++;
        }
    }
    return minLen == INT_MAX ?
                "" : s.substr(start, minLen);
}

//方法二：
 unordered_map <char, int> ori, cnt;//ori表示t字符串的哈希表，cnt表示s字符串的哈希表
    bool check() {//如果t中字符（包含重复的字符）都可以在s的子串中找到，就返回真
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {//先向右移动r，如果s[r]在t中出现，计数+1
                ++cnt[s[r]];
            }
            while (check() && l <= r) {//如果s的子串包含t中字符，且左指针小于右指针
                if (r - l + 1 < len) {//如果子串长度小于目前最优解，则更新最小覆盖子串
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];//减去计数，并向右移动l指针
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
```
## 无重叠区间

1.题目
```
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
注意:可以认为区间的终点总是大于它的起点。区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
```
2.vector中自定义sort函数的比较函数

**注意是用vector数组第二个元素大小降序排列，且注意函数前加static**
```C++
static bool cmp(vector<int>& a,vector<int>& b){
            return a[1]<b[1];//以一维数组第二个元素比较大小
        };
```

3.思路

+ 正确的思路其实很简单，可以分为以下三步：
  - 从区间集合 intvs 中选择一个区间 x，这个 x 是在当前所有区间中结束最早的（end 最小）。
  - 把所有与 x 区间相交的区间从区间集合 intvs 中删除。
  - 重复步骤 1 和 2，直到 intvs 为空为止。之前选出的那些 x 就是最大不相交子集。
  - 把这个思路实现成算法的话，可以按每个区间的 end 数值升序排序，因为这样处理之后实现步骤 1 和步骤 2 都方便很多。
+ 代码
```C++
 static bool cmp(vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len==0) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int count = 1;
        int end = intervals[0][1];
        for(int i = 0;i<len;i++){
            if(intervals[i][0]>=end){
                count++;
                end = intervals[i][1];
            }
        }
        int res = len - count;
        return res;
    }
```
## 合并区间

1.题目
```
给出一个区间的集合，请合并所有重叠的区间。区间集合的顺序是不规则的。
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```
2.分析

+ 排序后比较右端点数大小。我们用数组 merged 存储最终的答案。
  - 首先，我们将列表中的区间**按照左端点升序排序**。然后我们将第一个区间加入 merged 数组中，并按顺序依次考虑之后的每个区间：
  - 如果**当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合**，我们可以直接将这个区间加入数组 merged 的末尾；
  - 否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。
+ 实现：
```C++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
```
## 区间交集
1.题目
```
给定两个由一些 闭区间 组成的列表，每个区间列表都是成对不相交的，并且已经排序。
返回这两个区间列表的交集。

输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
```
2.实现
```C++
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        if(A.size()==0||B.size()==0) return ans;
        int i=0,j=0,lo,hi;
        while(i<A.size()&&j<B.size()){
            lo=max(A[i][0],B[j][0]);
            hi=min(A[i][1],B[j][1]);
            if(lo<=hi){
                ans.push_back({lo,hi});
            }
            if(A[i][1]<B[j][1]){i++;}
            else j++;
        }
        return ans;
    }
};
```
## 信封嵌套问题

1.题目
```
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
说明:
不允许旋转信封。

示例:
输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
```
2.分析和实现
+ 排序：排序的主要作用是降维，将二维数组转换为一维数组，然后进行寻找最长上升子序列。
+ 若w不相同，则按w由小到大进行排序。这样做的好处是：由于w由小到大进行排序了，那么只有h是上升的才能构成上升的子序列（即w已经可套娃了，判断h是否可套娃即可）。比如[1,1]、[2,0]、[3,1]、[4,2]，降维之后的数组为[1,0,1,2]，这里可套娃的子序列有[1,1]、[4,2]对应[1,2]，还有[2,0]、[3,1]、[4,2]对应[0,1,2]等。
+ 若w相同，则按h由大到小排序进行排序。这样做的好处是：由于w相等，那么只有h由大到小排序才不会计算重复的子序列（即w相等，只有h由大到小排序才不会重复计算套娃信封）。比如[3,4]、[4,6]、[4,7]，若按h由小到大排序降维之后的数组为[4,6,7]，这样形成的可套娃的序列长度为3，这个是不正确的，因为只有(w2>w1,h2>h1)才能进行套娃。若我们按h由大到小排序之后降维之后的数组为[4,7,6]，这样可形成两个长度为2的可套娃子序列[3,4]、[4,7]和[3,4]、[4,6]，这样便满足条件了。
+ 实现
```C++
class Solution {
public:
    //题解1：动态规划，时间复杂度O(n^2)，空间复杂度O(n)
    int maxEnvelopes_1(vector<vector<int>>& envelopes) {
        if(envelopes.empty())return 0;
        //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        int n=envelopes.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(envelopes[j][1]<envelopes[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }

    //优化：动态规划+二分法，时间复杂度O(nlogn)，空间复杂度O(n)
    int maxEnvelopes(vector<vector<int>>& envelopes){
        if(envelopes.empty())return 0;
      //先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        vector<int> dp;
        for(auto& en:envelopes){
            int idx=lower_bound(dp.begin(),dp.end(),en[1])-dp.begin();
            if(idx>=dp.size()){
                dp.emplace_back(en[1]);
            }
            else{
                dp[idx]=en[1];
            }
        }
        return dp.size();
    }
};
```
## 有序数组中去除重复元素
1.题目
```
给你一个数组 nums 和一个值 val，你需要 原地 移除所有重复的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
```
2.实现
```C++
int removeDuplicates(vector<int> nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int slow = 0, fast = 1;
    while (fast < n) {
        if (nums[fast] != nums[slow]) {
            slow++;
            // 维护 nums[0..slow] 无重复
            nums[slow] = nums[fast];
        }
        fast++;
    }
    // 长度为索引 + 1
    return slow + 1;
}
```
## 去除链表中重复元素
1.题目
```
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
示例 1:
输入: 1->1->2
输出: 1->2
示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
```
2.实现
```C++
ListNode* deleteDuplicates(ListNode* head) {
    if (head == null) return null;
    ListNode* slow = head, fast = head->next;
    while (fast != null) {
        if (fast->val != slow->val) {
            // nums[slow] = nums[fast];
            slow->next = fast;
            // slow++;
            slow = slow->next;
        }
        // fast++
        fast = fast->next;
    }
    // 断开与后面重复元素的连接
    slow->next = null;
    return head;
}
```
## 单链表操作
```C++
#include <iostream>
using namespace std;

class MyListForward
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(nullptr){}
    };
    ListNode* head;
public:
    MyListForward():head(nullptr){}

    //1、获得链表中第index个节点的值
    int get(int index){
        int i=0;
        ListNode *p=head;
        while(p&&i<index){
            p=p->next;
            i++;
        }
        if(p)return p->val;
        else return -1;
    }

    //2、在链表头部插一个值为val的节点
    void addAtHead(int val){
        ListNode *p=new ListNode(val);
        p->next=head;
        head=p;//更换头节点
    }

    //3、在链表尾部添加一个值为val的节点
    void addAtTail(int val){
        ListNode *p=new ListNode(val);
        //链表为空，直接将新节点作为头节点
        if(head==nullptr){
            head=p;
            return;
        }
        ListNode *q=head;
        //遍历直到q的next节点为空
        while(q->next){
            q=q->next;
        }
        q->next=p;
    }

    //4、在索引为index的节点之前添加值为val的节点
    void addAtIndex(int index,int val){
        ListNode *node=new ListNode(val);
        //1、index小于等于0，直接在头部插入节点
        if(index<=0)
        {//若index小于等于0，我们仅需要在头节点前面插入新节点就行了
        //注意这里不能使用指针p，因为p=node时，p所指向的地址发生了变化，head指向的地址没有变化，所以我们这里要使用指针head
            node->next=head;
            head=node;
            return;
        }
        int i=0;
        ListNode *p=head;
        //在索引为index的节点之前插入新节点，我们需要找到它的前驱节点，然后插入在它的前驱节点后面
        while(p&&i<index-1)
        {
            p=p->next;
            ++i;
        }
        //2、p为索引节点的前驱节点
        if(p)
        {
            node->next=p->next;
            p->next=node;
        }
    }

    //5、删除索引为index的节点
    void deleteAtIndex(int index){
        //1、index为0，我们直接删除head节点
        if(index==0&&head!=nullptr)
        {
            ListNode *del=head;
            head=head->next;
            delete del;
            return;
        }
        int i=0;
        ListNode* p=head;
        //删除索引为index的节点，我们需要找到它的前驱节点p，p->next为需要删除节点
        while(p&&i<index-1)
        {
            p=p->next;
            i++;
        }
        //2、index超过链表范围，删除失败
        if(!p)return;
        //3、index的位置合法，我们找到需要删除的p->next节点
        if(p->next)
        {
            ListNode *del=p->next;
            p->next=del->next;
            delete del;
        }
    }

    //6、链表长度
    int length(){
        int i=0;
        ListNode *p=head;
        while(p){
            i++;
            p=p->next;
        }
        return i;
    }

    //7、清空链表
    void clear(){
        ListNode *del=nullptr;
        while(head){
            del=head;
            head=head->next;
            delete del;
        }
    }
};

int main()
{
    MyListForward mlf;
    mlf.addAtIndex(0,10);
    mlf.addAtIndex(0,20);
    mlf.addAtIndex(1,30);
    for(int i=0;i<mlf.length();++i){
        cout<<mlf.get(i)<<" ";
    }
    cout<<endl;
    mlf.clear();
    cout<<mlf.length()<<endl;
    system("pause");
}
```
## 双向链表操作
```C++
#include <iostream>
using namespace std;

class MyList
{
private:
    struct ListNode
    {
        int val;
        ListNode *next,*prev;
        ListNode(int x):val(x),next(nullptr),prev(nullptr){}
    };
private:
    //头节点尾节点都为空，表示为空链表
    ListNode *head,*tail;
    int size=0;
public:
    MyList():size(0),head(nullptr),tail(nullptr){}

    //1、获得索引为index的节点值
    int get(int index){
        int i=0;
        ListNode *p=head;
        while(p&&i<index){
            p=p->next;
            i++;
        }
        if(p)return p->val;
        else return -1;
    }

    //2、在头部插入值为val的新节点
    void addAtHead(int val){
        if(head!=nullptr){
            ListNode *node=new ListNode(val);
            node->next=head;
            head->prev=node;
            head=node;
        }
        else{
            head=new ListNode(val);
            tail=head;
        }
        ++size;
    }

    //3、在尾部插入值为val的新节点
    void addAtTail(int val){
        if(tail!=nullptr){
            ListNode *node=new ListNode(val);
            node->prev=tail;
            tail->next=node;
            tail=node;
        }
        else{//尾节点为空，那么头节点也为空，然后首尾节点都为新节点
            tail=new ListNode(val);
            head=tail;
        }
        ++size;
    }

    //4、在index之前添加值为val的新节点
    void addAtIndex(int index,int val){
        //首先排除三种特殊情况的index，然后剩下来的index肯定在链表内
        if(index<=0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        if(index>size)return;
        ListNode *p=nullptr,*cur=head;
        int i=0;
        while(cur&&i<index){
            p=cur;
            cur=cur->next;
            i++;
        }
        ListNode *node=new ListNode(val);
        //由于前面已经将特殊情况的index排除了，现在的p和cur都有效，都在链表内
        p->next=node;
        node->prev=p;
        node->next=cur;
        cur->prev=node;
        size++;
    }

    //5、删除索引为index的节点
    void deleteAtIndex(int index){
        //链表为空时，不能删除
        if(!head)return;
        if(index==0)
        {
            ListNode *del=head;
            head=head->next;
            if(head){//链表有2个以上节点
                head->prev=nullptr;
            }
            else{//链表只有一个节点，将尾部制空
                tail=nullptr;
            }
            delete del;
            size--;
            return;
        }
        //index为最后为尾节点，我们需要删除尾节点
        if(index==size-1){
            ListNode *del=tail;
            tail=tail->prev;
            //注意这里不用处理tail为空，因为tail为空的话，那么链表只有单个节点
            //然而单个节点只能删除0号节点，只有index为0时才能删除，前面已经处理过了index为0的情况了，所以这里不在处理
            if(tail){
                tail->next=nullptr;
            }
            delete del;
            size--;
            return;
        }
        int i=0;
        ListNode *p=nullptr,*cur=head;
        while(cur){
            if(i==index){
                ListNode *del=cur;
                p->next=cur->next;
                if(cur->next){
                    cur->next->prev=p;
                }
                delete del;
                size--;
                return;
            }
            p=cur;
            cur=cur->next;
            ++i;
        }
    }

    //6、获得链表的长度
    int length(){
        return size;
    }

    //7、清空链表
    void clear(){
        for(int i=size-1;i>=0;--i){
            deleteAtIndex(i);
        }
    }
};

int main()
{
    MyList ml;
    ml.addAtHead(1);
    ml.addAtTail(3);
    ml.addAtHead(4);
    ml.addAtHead(5);
    ml.addAtIndex(1,2);
    for(int i=0;i<ml.length();++i){
        cout<<ml.get(i)<<" ";
    }
    cout<<endl;
    ml.deleteAtIndex(1);
    for(int i=0;i<ml.length();++i){
        cout<<ml.get(i)<<" ";
    }
    cout<<endl;
    ml.clear();
    cout<<ml.length()<<endl;
    system("pause");
}
```

## 反转链表的一部分

1.题目
```
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
```
2.实现
+ 迭代做法
```C++
class Solution {
public:
    //思路：head表示需要反转的头节点，pre表示需要反转头节点的前驱节点
    //我们需要反转n-m次，我们将head的next节点移动到需要反转链表部分的首部，需要反转链表部分剩余节点依旧保持相对顺序即可
    //比如1->2->3->4->5,m=1,n=5
    //第一次反转：1(head) 2(next) 3 4 5 反转为 2 1 3 4 5
    //第二次反转：2 1(head) 3(next) 4 5 反转为 3 2 1 4 5
    //第三次发转：3 2 1(head) 4(next) 5 反转为 4 3 2 1 5
    //第四次反转：4 3 2 1(head) 5(next) 反转为 5 4 3 2 1
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *pre=dummy;
        for(int i=1;i<m;++i)pre=pre->next;
        head=pre->next;
        for(int i=m;i<n;++i){
            ListNode *nxt=head->next;
            //head节点连接nxt节点之后链表部分，也就是向后移动一位
            head->next=nxt->next;
            //nxt节点移动到需要反转链表部分的首部
            nxt->next=pre->next;
            pre->next=nxt;//pre继续为需要反转头节点的前驱节点
        }
        return dummy->next;
    }
};
```
+ 递归做法
```C++
ListNode* successor = null; // 后驱节点
// 反转以 head 为起点的 n 个节点，返回新的头结点
ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) { 
        // 记录第 n + 1 个节点
        successor = head->next;
        return head;
    }
    // 以 head.next 为起点，需要反转前 n - 1 个节点
    ListNode* last = reverseN(head->next, n - 1);

    head->next->next = head;
    // 让反转之后的 head 节点和后面的节点连起来
    head->next = successor;
    return last;
} 
ListNode* reverseBetween(ListNode* head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }
    // 前进到反转的起点触发 base case
    head->next = reverseBetween(head->next, m - 1, n - 1);
    return head;
}
```
## 判断一个点是否在三角形内
[使用叉乘判断的解析](https://blog.csdn.net/pdcxs007/article/details/51436483?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.nonecase)
1.分析
+ 点P在三角形ABC内部，可以通过以下三个条件判断：
  - 点P和点C在直线AB同侧
  - 点P和点B在直线AC同侧
  - 点P和点A在直线BC同侧
+ 叉乘是一个判断点在直线哪一侧的数学工具。
  - u⃗ ×v⃗ =(u2v3−u3v2)i⃗ +(u3v1−u1v3)j⃗ +(u1v2−u2v1)k⃗

2.实现
```C++
          C
	 / \
	/ P \
       /     \
      A——————-B
//注意这样一下子写出来不太容易看明白，但是如果看成向量AB和向量AC叉乘之后的Z坐标就好懂的多了。
//u⃗ ×v⃗ =(u2v3−u3v2)i⃗ +(u3v1−u1v3)j⃗ +(u1v2−u2v1)k⃗ 
float signOfTrig = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);//AB X AC
//再分别计算P在AB、CA、BC的哪一侧：
float signOfAB = (b.x - a.x)*(p.y - a.y) - (b.y - a.y)*(p.x - a.x);// AB X AP(P在AB左侧)
float signOfCA = (a.x - c.x)*(p.y - c.y) - (a.y - c.y)*(p.x - c.x);// CA X CP(P在CA左侧)
float signOfBC = (c.x - b.x)*(p.y - b.y) - (c.y - b.y)*(p.x - b.x);// BC X BP(P在BC左侧)
boolean d1 = (signOfAB * signOfTrig > 0);
boolean d2 = (signOfCA * signOfTrig > 0);
boolean d3 = (signOfBC * signOfTrig > 0);
println(d1 && d1 && d3);
```
## 平衡二叉树
1.题目
```C++
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
```
2.分析
+ **自顶向下的方法**：具体做法类似于二叉树的前序遍历，即对于当前遍历到的节点，首先计算左右子树的高度，如果左右子树的高度差是否不超过 1，再分别递归地遍历左右子节点，并判断左子树和右子树是否平衡。这是一个自顶向下的递归的过程。**时间复杂度最高达到O(n^2)**.
```C++
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int h = abs(get_height(root->left)-get_height(root->right));
        return h<=1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int get_height(TreeNode* root){
        if(root == NULL) return 0;
        int h = max(get_height(root->left),get_height(root->right));
        return h+1;
    }
};
```
+ **自底向上的方法**:由于自顶向下递归，对于同一个节点，函数会被重复调用，导致时间复杂度较高。如果使用自底向上的做法，则对于每个节点，函数 height 只会被调用一次。自底向上递归的做法类似于后序遍历，对于当前遍历到的节点，先递归地判断其左右子树是否平衡，再判断以当前节点为根的子树是否平衡。如果一棵子树是平衡的，则返回其高度（高度一定是非负整数），否则返回 −1。如果存在一棵子树不平衡，则整个二叉树一定不平衡。
```C++
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};
```
## 有序链表转换为二叉搜索树
1.题目
```
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定的有序链表： [-10, -3, 0, 5, 9],
一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
```
2.分析
+ 容易想到的直接递归
```C++
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> memo;
        while(head){
            memo.push_back(head->val);
            head = head->next;
        }
        int len = memo.size();
        TreeNode* ans = helper(memo,0,len-1);
        return ans;
    }
    TreeNode* helper(vector<int> memo, int left_start, int right_end){
        if(left_start > right_end){
            return nullptr;
        }
        int mid = (left_start+right_end)/2;
        TreeNode* root = new TreeNode(memo[mid]);
        root->left = helper(memo,left_start,mid-1);
        root->right = helper(memo,mid+1,right_end);
        return root;
    }
};
```
+ 时间复杂度的瓶颈在于寻找中位数节点。由于构造出的二叉搜索树的中序遍历结果就是链表本身，因此我们可以将分治和中序遍历结合起来，减少时间复杂度。具体地，设当前链表的左端点编号为 left，右端点编号为 right，包含关系为「双闭」，即 left 和 right 均包含在链表中。链表节点的编号为 [ 0,n)]。中序遍历的顺序是「左子树 - 根节点 - 右子树」，**那么在分治的过程中，我们不用急着找出链表的中位数节点，而是使用一个占位节点，等到中序遍历到该节点时，再填充它的值**。
```C++
class Solution {
public:
    int getLength(ListNode* head) {//计算链表长度
        int ret = 0;
        for (; head != nullptr; ++ret, head = head->next);
        return ret;
    }

    TreeNode* buildTree(ListNode*& head, int left, int right) {
        if (left > right) {//递归返回条件
            return nullptr;
        }
        int mid = (left + right + 1) / 2;
        TreeNode* root = new TreeNode();//占位结点
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        return buildTree(head, 0, length - 1);
    }
};
```
## 数组的子集排列组合问题

1.输入一个不包含重复数字的数组，要求算法输出这些数字的所有子集。
```C++
//复杂的方法
vector<vector<int>> subsets(vector<int>& nums) {
    // base case，返回一个空集
    if (nums.empty()) return {{}};
    // 把最后一个元素拿出来
    int n = nums.back();
    nums.pop_back();
    // 先递归算出前面元素的所有子集
    vector<vector<int>> res = subsets(nums);

    int size = res.size();
    for (int i = 0; i < size; i++) {
        // 然后在之前的结果之上追加
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    return res;
}
//回溯算法
vector<vector<int>> res;

vector<vector<int>> subsets(vector<int>& nums) {
    // 记录走过的路径
    vector<int> track;
    backtrack(nums, 0, track);
    return res;
}

void backtrack(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);
    for (int i = start; i < nums.size(); i++) {
        // 做选择
        track.push_back(nums[i]);
        // 回溯
        backtrack(nums, i + 1, track);
        // 撤销选择
        track.pop_back();
    }
}
```
2.输入两个数字 n, k，算法输出 [1..n] 中 k 个数字的所有组合。
+ 递归版本
```C++
vector<vector<int>>res;

vector<vector<int>> combine(int n, int k) {
    if (k <= 0 || n <= 0) return res;
    vector<int> track;
    backtrack(n, k, 1, track);
    return res;
}

void backtrack(int n, int k, int start, vector<int>& track) {
    // 到达树的底部
    if (k == track.size()) {
        res.push_back(track);
        return;
    }
    // 注意 i 从 start 开始递增
    for (int i = start; i <= n; i++) {
        // 做选择
        track.push_back(i);
        backtrack(n, k, i + 1, track);
        // 撤销选择
        track.pop_back();
    }
}
```
+ 非递归字典序方法
```C++
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr(k);
	//定义在 numeric 头文件中的 iota() 函数模板会用连续的 T 类型值填充序列。前两个参数是定义序列的正向迭代器，第三个参数是初始的 T 值。
        std::iota(curr.begin(), curr.end(), 1); // 初始化序列.std::iota :用顺序递增的值赋值指定范围内的元素 。
        vector<vector<int>> res;
        res.push_back(curr);   // 把初始序列放进去

        // 开始循环计算下一个序列
        int curr_idx = k-1;
        while(curr_idx >= 0) {
            // 第k个值的最大值是n,那么第k-1个值最大值就应该是n-1, 所以当前要比较的是当前位置的最大值.
            if(curr[curr_idx] < n-(k-1-curr_idx)) {
                // 如果当前指向的值可以加1,那么直接增加.
                ++curr[curr_idx];
                if(curr_idx < k-1) {    // 如果当前增加的位不是末尾, 那么需要重置后续的位.
                    int next_idx = curr_idx + 1;
                    while(next_idx < k) {
                        curr[next_idx] = curr[next_idx-1] + 1;
                        ++next_idx;
                    }
                    curr_idx = k-1;     // 然后把当前指向的位修改为最后一位.
                }
                res.push_back(curr);
            }
            else {
                // 如果小于当前位置的最大值,那么就需要向前找一位,所以把当前指向的位前移.
                --curr_idx;
            }
        }
        return res;
    }
};
```

3.输入一个不包含重复数字的数组 nums，返回这些数字的全部排列。
```C++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        paths.clear();
        path.clear();

        vector<int> used(nums.size(),false);

        helper(nums,used);

        return paths;
    }
private:
    void helper(vector<int>& nums,vector<int>& used) {
        if(path.size() == nums.size()) {
            paths.push_back(path);
            return ;
        }

        for(int i = 0 ; i < nums.size() ; ++i) {
            if(used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);
            
            helper(nums,used);

            path.pop_back();
            used[i] = false;
        }
    }
private:
    vector<vector<int>> paths;
    vector<int> path;
};
```
## 最长回文子序列

1.题目
```
给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000
```
一道典型的动态规划问题！

2.实现

[详细解答见此文章](https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E5%AD%90%E5%BA%8F%E5%88%97%E9%97%AE%E9%A2%98%E6%A8%A1%E6%9D%BF.md)
```C++
int longestPalindromeSubseq(string s) {
    int n = s.size();
    // dp 数组全部初始化为 0
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // base case
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    // 反着遍历保证正确的状态转移
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // 状态转移方程
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    // 整个 s 的最长回文子串长度
    return dp[0][n - 1];
}
```
## LFU缓存机制
```
请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。它应该支持以下操作：get 和 put。
get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除最久未使用的键。
「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。
```

1.首先需要定义一个缓存的数据结构
```C++
struct Node {
    int cnt;//缓存使用频率
    int time;//缓存使用时间
    int key, value;
    Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}
    // 我们需要实现一个 Node 类的比较函数
    // 将 cnt（使用频率）作为第一关键字，time（最近一次使用的时间）作为第二关键字
    // 下面是 C++ 语言的一个比较函数的例子
    bool operator< (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
```
2.比较直观的想法就是用哈希表 key_table 以键 key 为索引存储缓存，建立一个平衡二叉树 S 来保持缓存。在 C++ 中，可以使用 STL 提供的 std::set 类，set 背后的实现是红黑树：

+ 对于 get(key) 操作，只要查看一下哈希表 key_table 是否有 key 这个键即可，有的话需要同时更新哈希表和集合中该缓存的使用频率以及使用时间，否则返回 -1。
+ 对于 put(key, value) 操作，首先需要查看 key_table 中是否已有对应的键值。如果有的话操作基本等同于 get(key)，不同的是需要更新缓存的 value 值。如果没有的话相当于是新插入一个缓存，这时候需要先查看是否达到缓存容量 capacity，如果达到了的话，需要删除最近最少使用的缓存，即平衡二叉树中最左边的结点，同时删除 key_table 中对应的索引，最后向 key_table 和 S 插入新的缓存信息即可。
```C++
class LFUCache {
    // 缓存容量，时间戳
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity; time = 0;key_table.clear(); S.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it -> second = cache;
        return cache.value;
    }
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else {
            // 这里和 get() 函数类似
            Node cache = it -> second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it -> second = cache;
        }
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 }
```
## 回文字符串总数
1.题目
```
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例 1：
输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：
输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
```
2.实现
```C++
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};
```
## 判断ip地址是否合法
```C++
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
    int n, number, len；
    int num=0;   //计数器
    int rcount=0;   //计算合法数字的个数
    string p, snum="";
    string adr[5];   //保存各个数字
    cin >> n;    //输入字符串的个数
    for(int i=0;i<n;i++)
    {
        cin >> p;
        len = p.size();
        for(int j=0;j<len;j++)
        {
            if(p[j]=='.')
            {
                adr[num++] = snum;   //将合并的字符串存入数组
                snum = "";
            }
            else
                snum += p[j];   //字符合并为字符串
        }
        adr[num] = snum;   //将最后一个小数点后的数字存入
        if(num!=3)   //判断格式是否为a.b.c.d
        {
            cout << "NO" << endl;
        }
        else
        {
            for(int j=0;j<4;j++)
            {
                number = atoi(adr[j].c_str());   //string转int
                if(number>=0 && number<=255)   //判断数字是否合法
                    rcount += 1;
            }
            if(rcount == 4)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
```
## 生成100以内不重复的随机数
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<ctime>

using namespace std;

int main() {
    vector<int> vec(100), res;
    for (int i = 0; i < 100; i++)
        vec[i] = i;
    int n = 100;
    while(n)
    {
        //int curr = dist(rengine) % n;
        srand(int(time(0)));
        int curr = rand() % n;
        res.push_back(vec[curr]);
        vec.erase(vec.begin()+curr);
        n--;
    }
    for (auto &a : res)
        cout << a << " ";
    return 0;
}
```
## memcpy与strcpy
[一篇介绍](https://blog.csdn.net/goodwillyang/article/details/45559925)

1.知识点
+ memcpy函数 void  *memcpy(void *s1,  const void *s2,  size_t  n);
  - 说明：函数memcpy从s2指向的对象中复制n个字符到s1指向的对象中。如果复制发生在两个重叠的对象中，则这种行为未定义。
  - 要破坏传进来的形参，定义新的临时变量来操作
  - 考虑指针的类型，不同类型的指针不能直接++赋值
  - overlap情况下需要从高地址处向前copy
  - memcpy用来在内存中复制数据，由于字符串是以“\0”结尾的，所以对于在数据中包含“\0”的数据只能用memcpy，如:"hell\0oworld"。
+ strcpy函数 char  *strcpy(char *s2, const char *s1);
  - 说明：函数strcpy把s1指向的串（包括空字符）复制到s2指向的数组中。如果复制发生在两个重叠的对象中，则这种行为未定义。
  - strcpy 是依据 “\0” 作为结束判断的，如果 s2 的空间不够，则会引起 buffer overflow。

2.实现
```C++
char* strcpy(char * dest, const char * src) // 实现src到dest的复制
{
　　if ((src == NULL) || (dest == NULL)) //判断参数src和dest的有效性
　　{
　　　　　　return NULL;
　　}
　　char *strdest = dest;        //保存目标字符串的首地址
　　while ((*strDest++ = *strSrc++)!='\0'); //把src字符串的内容复制到dest下
　　return strdest;
}

void* memcpy(void *memTo, const void *memFrom, size_t size)
{
　　if((memTo == NULL) || (memFrom == NULL)) //memTo和memFrom必须有效

         return NULL;
　　char *tempFrom = (char *)memFrom;             //保存memFrom首地址
　　char *tempTo = (char *)memTo;                  //保存memTo首地址     
　　while(size-- > 0)                //循环size次，复制memFrom的值到memTo中
       　　*tempTo++ = *tempFrom++ ; 
　　return memTo;
}
//地址重叠解决版本memcpy
void *memcpy(void *dest, const void *src, size_t count)
{
 char *d;
 const char *s;
 
 if (dest > (src+size)) || (dest < src))
    {
    d = dest;
    s = src;
    while (count--)
        *d++ = *s++;        
    }
 else /* overlap */
    {
    d = (char *)(dest + count - 1); /* offset of pointer is from 0 */
    s = (char *)(src + count -1);
    while (count --)
        *d-- = *s--;
    }
  
 return dest;
}
```
## 高效数组排序
```C++
//将数组中非零元素移至左侧，0移至右侧，并保证相对顺序不变
#include <iostream>
#include <vector>

using namespace std;

vector<int> sort_array(vector<int>& nums){
    int ptr_zero = 0;
    int ptr_num = 0;
    while(ptr_zero < nums.size() && nums[ptr_zero] != 0){
        ptr_zero++;
        ptr_num++;
    }
    while(ptr_num<nums.size() && ptr_zero<nums.size()){
        if(nums[ptr_num] == 0){
            ptr_num++;
            continue;
        }
        swap(nums[ptr_zero],nums[ptr_num]);
        ptr_zero++;
        ptr_num++;
    }
    return nums;
}

int main() {
    vector<int> nums = {1,0,-1,3,5,0,0,-5};
    vector<int> ans = sort_array(nums);
    for(auto num:nums){
        cout<<num<<" ";
    }
    return 0;
}

```
## 反转字符串中的单词III
1.题目
```
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
```
2.实现
```C++
//复杂方法
class Solution {
public:
    string reverseWords(string s) {
        if(s == ""){
            return "";
        }
        istringstream str(s);
        string ans;
        string temp;
        while(str>>temp){
            reverse(temp.begin(),temp.end());
            ans += temp + " ";
        }
        ans.pop_back();
        return ans;
    }
};
//原地翻转
class Solution {
public: 
    string reverseWords(string s) {
        int length = s.length();
        int i = 0;
        while (i < length) {
            int start = i;
            while (i < length && s[i] != ' ') {
                i++;
            }

            int left = start, right = i - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            while (i < length && s[i] == ' ') {
                i++;
            }
        }
        return s;
    }
};
```
## 判断一个数是否为2的n次方
```C++
//判断一个数是否为2的n次方
bool judge(int n){
	if n <= 0 {
		return false;
	}
	return n&(n-1) == 0;
}
//求两数的最大公约数和最小公倍数
using namespace std;
class Calculate//建立一个类
{
private:
	int m;
	int n;
	int temp;  //用于两数转换
	int d;     //余数
	int max;   //最大公因数
	int min;   //最小公倍数
	int product;   //m和n的乘积
public:
	void MAX_common(); //最大公因数算法
	void MIN_multiple(); //最小公倍数
	void cycle();  //选择方法循环
};
void Calculate::MAX_common()//辗转相除法
{
	cout<<"请输入你需要计算的两个数：(x x)"<<endl;
	cin>>m>>n;
	product=m*n;
	if(m<n)//交换数值永远保持m是最大的值
	{
		temp=m;
		m=n;
		n=temp;
 
 
	};
	d=m%n;  //求余
	if(d==0)  //
		max=n;
	else
		while(d!=0)//直到余数为0
		{
			m=n;
			n=d;
			d=m%n;
			max=n;
		};
	min=product/max;
	cout<<"最大公因数为："<<max<<endl;
	cout<<"最小公倍数为："<<min<<endl;
}
```
## 二叉树前中后序遍历的非递归方法

1.二叉树前序遍历的迭代方法
+ 在迭代算法中，思路演变成，每到一个节点 A，就应该立即访问它。因为，每棵子树都先访问其根节点。对节点的左右子树来说，也一定是先访问根。在 A 的两棵子树中，遍历完左子树后，再遍历右子树。
因此，在访问完根节点后，遍历左子树前，要将右子树压入栈。
```C++
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* rt = root;
        while(rt || stk.size()){
            while(rt){
                stk.push(rt->right);
                res.push_back(rt->val);
                rt=rt->left;
            }
            rt=stk.top();
	    stk.pop();
        }
        return res;        
    }
```
2.二叉树后序遍历的迭代方法
+ 方法一：按照根-右-左的顺序遍历树后，翻转数组
```C++
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* rt = root;
        while(rt || stk.size()){
            while(rt){
                stk.push(rt->left);
                res.push_back(rt->val);
                rt=rt->right;
            }
            rt=stk.top();
	    stk.pop();
        }
        reverse(res.begin(),res.end());
        return v;
    }
```
+ 方法二：每到一个节点 A，因为根要最后访问，将其入栈。然后遍历左子树，遍历右子树，最后返回到 A。但是出现一个问题，无法区分是从左子树返回，还是从右子树返回。因此，给 A 节点附加一个标记T。在访问其右子树前，T 置为 True。之后子树返回时，当 T 为 True表示从右子树返回，否则从左子树返回。当 T 为 false 时，表示 A 的左子树遍历完，还要访问右子树。同时，当 T 为 True 时，表示 A 的两棵子树都遍历过了，要访问 A 了。并且在 A 访问完后，A 这棵子树都访问完成了。
```C++
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        unordered_map<TreeNode*,int> done;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt);
                rt=rt->left;
            }
            while(S.size() && done[S.top()]){
                v.push_back(S.top()->val);
                S.pop();
            }
            if(S.size()){
                rt=S.top()->right;
                done[S.top()]=1;    
            }
        }
        return v;
    }
```
3.二叉树中序遍历的迭代方法
+ 每到一个节点 A，因为根的访问在中间，将 A 入栈。然后遍历左子树，接着访问 A，最后遍历右子树。在访问完 A 后，A 就可以出栈了。因为 A 和其左子树都已经访问完成。
```C++
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* rt = root;
        while(rt || stk.size()){
            while(rt){
                stk.push(rt);
                rt=rt->left;
            }
            rt=stk.top();
	    stk.pop();
            res.push_back(rt->val);
            rt=rt->right;
        }
        return res;        
    }
```
## 递归反转栈中元素
1.方法一
```C++
#include <iostream>

using namespace std;

class Stack{
public:
        Stack(int n){
                num = n;
                arr = new int[n]();
                t = -1;
        }

        ~Stack(){
                delete [] arr;
        }

        bool empty()
        { return t<0; }

        void push(int val)
        {
                t++;
                if(t >= num)
                {       cout<<"the stack is full"<<endl;
                        return; 
                }else
                        arr[t] = val;
                return;
        }

        void pop()
        {
                if( t<0 )
                {       cout<<"the stack is empty, can't pop'"<<endl;
                        return;
                }else
                        t--;
        }

        int top()
        {
                if(t<0)
                {       cout<<"the stack is empty";
                        return -1;
                }else
                        return arr[t];
        }

public:
        int *arr;
private:
        int num;
        int t;
};

void print(Stack &stk)
{
        if(!stk.empty())
        {
                int temp = stk.top();
                cout<<temp;
                stk.pop();
                print(stk);
                stk.push(temp);
        }else{
                cout<<endl;
        }
        return;
}

void insertBottom(Stack &stk, int val)
{
        if(stk.empty())
        {
                stk.push(val);
                return;
        }else{
                int temp = stk.top();
                stk.pop();
                insertBottom(stk, val);
                stk.push(temp);
                return;
        }
}

void reverse(Stack &stk)
{
        if(!stk.empty())
        {
                int temp = stk.top();
                stk.pop();
                reverse(stk);
                insertBottom(stk, temp);
        }
        return;
}

int main()
{
        int arr[] = {6,5,4,3,2,1};
        Stack stk(10);
        for(int i = 0; i<6; ++i)
                stk.push(arr[i]);
        print(stk);
        reverse(stk);
        print(stk);
}
```
2.方法二：
```C++
#include <iostream>
#include <stack>
using namespace std;

void printInfo(stack<int> s){
    int a ;
    while(!s.empty()){
        a = s.top();
        cout << a << " . " ;
        s.pop();
    }
    cout << endl;
    return ;
}

void reverseStack(stack<int> &s){
    if(s.empty())
        return ;
    else {
        //如果s里面只有一个元素，就返回，否则就不返回。具体实现是先pop出来一个，判断剩下的是不是空栈。
        int a = s.top();
        s.pop();
        if(s.empty()){
            s.push(a);
            return ;
        }
        else{
            s.push(a);
        }
    }
    int temp1 = s.top();
    s.pop();
    reverseStack(s);
    int temp2 = s.top();
    s.pop();
    reverseStack(s);
    s.push(temp1);
    reverseStack(s);
    s.push(temp2);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "-------------before recursion------------" << endl;
    printInfo(s);
    
    cout << "-------------after  recursion------------" << endl;
    reverseStack(s);
    printInfo(s);

    system("pause");
    return 0;
}
```
## C语言实现itoa
1.原型
```C
char *itoa( int value, char *string,int radix);
```

2.函数说明
+ value：欲转换的数据。
+ string：目标字符串的地址。
+ radix：转换后的进制数，可以是10进制、16进制等。

3.实现
```C++
#include <iostream> 
#include <string> 
using namespace std; 
  
char* My_itoa(int value,char str[],int radix) 
{ 
  char temp[33]; 
  char *tp = temp; 
  int i; 
  unsigned v; 
  int sign; 
  char *sp; 
  if(radix > 36 || radix < 1) 
    return 0; 
  sign = (radix == 10 && value < 0); //十进制负数 
  if(sign) 
    v = -value; 
  else
    v = (unsigned)value; 
  while(v || tp == temp)       //转化操作 
  { 
    i = v % radix; 
    v = v / radix; 
    if(i < 10) 
      *tp++ = i + '0'; 
    else
      *tp++ = i + 'a' - 10; 
  } 
  if(str == 0) 
    str = (char*)malloc((tp - temp) + sign + 1); 
  sp = str; 
  if(sign)   //是负数的话把负号先加入数组 
    *sp++ = '-'; 
  while(tp > temp) 
    *sp++ = *--tp; 
  *sp = 0; 
  
  return str; 
} 
  
int main() 
{ 
  long int num; 
  int radix;   //输入的几进制表示 
  char str[256]; 
  cout<<"请输入整数和进制数："; 
  cin>>num>>radix; 
  My_itoa(num,str,radix); 
  cout<<"整数转换为字符串后："; 
  cout<<str<<endl; 
  
  return 0; 
} 
```
## 随机洗牌
```C++      
#include <iostream>
#include<cstdlib>
#include<vector>
#include<random>
#include<ctime> 
#define N 54
using namespace std;
void xipai(vector<int>&data){
    int cnt;
    for(int i=0;i<N;++i){
    	srand(int(time(0)));
        cnt=rand()%(N-i);
        swap(data[cnt],data[N-i-1]);
    }
    return ;
}
int main()
{
    vector<int>data(N);
    for(int i=0;i<N;++i)
        data[i]=i+1;
    xipai(data);
    for(int i=0;i<N;++i)
        cout<<data[i]<<" ";
    return 0;
}
```
## 序列化和反序列化二叉搜索树

1.题目
```
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
设计一个算法来序列化和反序列化二叉搜索树。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
编码的字符串应尽可能紧凑。
```
2.实现
```C++
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "#";

        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* rebuildTree(stringstream &ss){
        string tmp;
        ss >> tmp;
        
        if(tmp == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = rebuildTree(ss);
        node->right = rebuildTree(ss);

        return node;
    }
    
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return rebuildTree(ss);
    }
};
```
## 长度最小的数组

1.题目
```
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
```
2.实现(典型的双指针！)
```C++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```
## 逆波兰表达式

1.题目
```
根据 逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```
2.实现
```C++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> memo_num;
        stack<string> memo_symbol;
        for(auto str : tokens){
            if(str != "+" && str!= "-" && str != "*" && str != "/"){
                int num;
                stringstream tmp;
                tmp<<str;
                tmp>>num;
                //int num = stoi(str);
                memo_num.push(num);
            }
            else{
                int num1 = memo_num.top();
                memo_num.pop();
                int num2 = memo_num.top();
                memo_num.pop();
                if(str == "+"){
                    int num = num1 + num2;
                    memo_num.push(num);
                }
                if(str == "-"){
                    int num = num2 - num1;
                    memo_num.push(num);
                }
                if(str == "*"){
                    int num = num2 * num1;
                    memo_num.push(num);
                }
                if(str == "/"){
                    int num = num2 / num1;
                    memo_num.push(num);
                }            
            }
        }
        int ans = memo_num.top();
        return ans;
    }
};
```
## 验证IP地址
1.题目
```
编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址。

IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；

同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。

IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。

然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。

同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。
```
2.实现
```C++
class Solution {
public:
    bool isIPv4Num(string num) {
        if (num == "") {
            return false;
        }
        if (num.size()>1&&num[0]=='0') {
            
            return false;
        }
        stringstream is(num);
        int b;
        is>>b;
        if (to_string(b) != num) return false;
        if (b>=0&&b<=255) {
            return true;
        }
        return false;
        
    }
    bool isIPv6Num(string num) {
        if (num == "") {
            return false;
        }
        if (num == "0") return true;
        if (num.size() > 4) {
            
            return false;
        }
        for (auto n : num) {
            if ((n > 'F' && n <= 'Z')|| (n > 'f' && n <= 'z')) {
                return false;
            }
        }    
        return true;
        
    }
    bool isIPv4Address(string IP) {
        stringstream is(IP);
        string num;
        int count = 0;
        while(getline(is,num,'.')) {
            
            if (isIPv4Num(num) == false) {
                return false;
            }
            ++count;
            
        }
        if(count == 4) {
                return true;
            }
        return false;
    }
    bool isIPv6Address(string IP) {
        stringstream is(IP);
        string num;
        getline(is,num,':');
        if (num.size()<1) return false;
        if (num.size()>1&&num[0]=='0') return false;
        for (auto n : num) {
            if ((n > 'F' && n <= 'Z')|| (n > 'f' && n <= 'z')) {
                return false;
            }
        }
        int count = 0; 
        while(getline(is,num,':')) {
            
            if (isIPv6Num(num) == false) {
                return false;
            }
            ++count;
            
        }
        if(count == 7) {
                return true;
            }
        return false;
    }
    string validIPAddress(string IP) {
        if (IP.find(".") != string::npos) {
            if (isIPv4Address(IP) && IP[IP.size()-1] != '.') {
                return "IPv4";
            }
        }
        else if (IP.find(":") != string::npos) {
            if (isIPv6Address(IP) && IP[IP.size()-1] != ':') {
                return "IPv6";
            }
        }
         return "Neither";
    }
};
```
## 最长公共子序列与最长公共子串

1.实现
```C++

#include <iostream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;
 
int lcs(string str1, string str2) //最长公共子序列
{
	int len1 = str1.size();
	int len2 = str2.size();
	vector<vector<int>> c(len1 + 1, vector<int>(len2 + 1));
 
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else {
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}
	return c[len1][len2];
}
int lcs1(string str1, string str2) //最长公共子串
{
	int len1 = str1.size();
	int len2 = str2.size();
	int result = 0;     //记录最长公共子串长度
	vector<vector<int>> c(len1 + 1, vector<int>(len2 + 1));
 
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				result = max(c[i][j], result);
			}
			else {
				c[i][j] = 0;
			}
		}
	}
	return result;
}
int main()
{
	string str, str1, str2;
	str = "acbcbcef,abcbced";
	int i = 0;
	for (i = 0; i < str.size(); i++) {  //现将字符串以逗号进行分割
		if (str[i] != ',') {
			i++;
		}
		else { break; }
	}
	str1 = str.substr(0, i);
	str2 = str.substr(i + 1, str.size());
 
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;
 
	cout <<"最长公共子序列："<< lcs(str1, str2) << endl;
	cout << "最长公共子串：" << lcs1(str1, str2) << endl;
 
	return 0;
}
```
## 版本号比较

1.题目
```
比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。
你可以假设版本字符串非空，并且只包含数字和 . 字符。
 . 字符不代表小数点，而是用于分隔数字序列。
例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。
你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和 4。其第三级和第四级修订号均为 0。

示例 1:
输入: version1 = "0.1", version2 = "1.1"
输出: -1
示例 2:
输入: version1 = "1.0.1", version2 = "1"
输出: 1
示例 3:
输入: version1 = "7.5.2.4", version2 = "7.5.3"
输出: -1
示例 4：
输入：version1 = "1.01", version2 = "1.001"
输出：0
解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”。
```

2.实现
```C++
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        int end = max(version1.size(), version2.size());
        while (p1 < end || p2 < end) {
            int v1 = 0, v2 = 0;
            while (p1 < version1.size() && version1[p1] != '.') {
                v1 = v1 * 10 + version1[p1] - '0';
                p1++;
            }
            while (p2 < version2.size() && version2[p2] != '.') {
                v2 = v2 * 10 + version2[p2] - '0';
                p2++;
            }
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            p1++;
            p2++;
        }
        return 0;
    }
};
```
## 合并N个有序数组

1.题目
```
有N个长度为M的有序数组，每个数组不足M个元素时，用0补全。求合并后前k个元素
输入:
5 5 7
1 2 3 4 5
3 4 6 7 0
2 3 0 0 0
0 1 2 3 6
0 7 8 9 0
输出：
0 0 1 1 2 2 2
```
2.实现
```C++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


struct node{
    int value;
    int out_index;
    int in_index;
    node(int v, int o,int i){
        value = v;
        out_index = o;
        in_index = i;
    }
    bool operator<(node a)const{
        return value < a.value;
    }
    bool operator>(node a)const{
        return value > a.value;
    }
};
vector<int> mergeSort(vector<vector<int>> &nums){
    vector<int> res;
    priority_queue <node, vector<node>,greater<node>> order;
    int N = nums.size(), M = nums[0].size();
    for (int k = 0; k < N; k++){
        order.push(node(nums[k][0], k, 0));
    }
    int i = 0, j = 0;

    while (!order.empty()){
        node tmp = order.top();
        res.push_back(tmp.value);
        i = tmp.out_index;
        j = tmp.in_index + 1;
        order.pop();
        if (j == M || nums[i][j] == 0)
        {
            continue;
            //order.push(node(INT_MAX, i, j));
        }
        else
        {
            order.push(node(nums[i][j], i, j));
        }
    }
    return res;
}

int main(){
    int N,M;
    cin>>N>>M;
    int k;
    cin>>k;
    vector<vector<int>> nums;
    while(N){
        vector<int> temp;
        int num;
        while(cin>>num){
            temp.push_back(num);
            if(getchar() == '\n') break;
        }
        nums.push_back(temp);
        N--;
    }

    vector<int> res = mergeSort(nums);
    for(int i=0;i<k;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
```
## 路径总和III
1.题目
```
给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
示例：
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:
1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
```
2. 实现
+ [路径总和类的问题](https://leetcode-cn.com/problems/path-sum/)
+ 实现
```C++
class Solution {
public:

vector<vector<int>> ans;
vector<int> track;

void dfs(TreeNode* root, int sum)
{
    if(root == nullptr)
        return;
    track.push_back(root->val);
    sum -= root->val;
    if(sum == 0){
        ans.push_back(track);
    }
    dfs(root->left, sum);
    dfs(root->right, sum);
    track.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if(root == nullptr)
        return ans;
    dfs(root, sum);
    pathSum(root->left, sum);
    pathSum(root->right, sum);
    return ans;
}
};
```
## 二叉树的宽度
1.题目
```
给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。
每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
示例 1:
输入: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

输出: 4
解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
```
2.实现
```C++
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        int ans = 1;
        q.push({root, 1});
        while (!q.empty()) {
            int sz = q.size();
            ans = max(int(q.back().second - q.front().second + 1), ans);
            for (int i=0; i < sz; i++) {
                TreeNode *node = q.front().first;
                unsigned long long pos = q.front().second;
                q.pop();
                if (node->left) q.push({node->left, 2 * pos});
                if (node->right) q.push({node->right, 2 * pos + 1});
            }
        }
        return ans;
    }
};
```
## 二叉树完全性的检验
1.题目

2.实现
+ 两个条件 排除非完全二叉树：
  - 1、如果一个节点有右孩子，但没有左孩子，则不是完全二叉树 return false
  - 2、如果一个节点仅有左孩子，或左右都没有（即没有右孩子），则后续的节点都必须是叶子节点，才能是完全二叉树， 只要出现非叶子节点 return false
+ 实现
```C++
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        if (!root)
        {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leaf = false; //是否必须为叶子节点

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (!node->left && node->right) //仅有右子节点，无左子节点
            {
                return false;
            }
            if (leaf) //前面出现过无右子节点的 (只有左 或 左右都没有的) 后续所有节点必须为叶子节点
            {
                if (node->left || node->right) //非叶子节点
                {
                    return false;
                }
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
            else //右为空 则后续节点必须为叶子节点
            {
                leaf = true; 
            }
        }
        return true;
    }
};
```
## 合并二叉树
1.题目
```
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
示例 1:
输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
```
2.实现
+ [非递归版本](https://leetcode-cn.com/problems/merge-two-binary-trees/solution/he-bing-er-cha-shu-by-leetcode-solution/)
+ 
```C++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};
```
## 使用数组和链表实现队列

1.数组实现队列
+ 我们用 first 和 last 存储队列首元素和尾元素的下标。当队列为空时，习惯上设置 first 和 last 的值为-1。当数据入队时, 必须先++相应的下标，然后再存入数据。
+ 判断队列是否为空：这时只需要看 first 就可以，如果 first == -1 ， 队列即为空。
+ 判断队列是否已满：队列满队，有两种情况：
  - 1.当队列首次按顺序存满数据时，它的 first 等于0，指向storge数组第一个元素位置storge[0]，而它的last 等于size-1，指向storge数组最后一个元素storge[size-1]，此时队列已满。
  - 2.另外一种情况就是，但我们首次队列满时，将一些元素出队，由于队列是FIFO结构，从头部开始出队，这样在队列元素未全部出队的情况下，first 指向后移。当我们再次将一些数据入队时，last 从storge[size-1] 再次回到 storge[0]，然后按照队列顺序入队，当last = first -1 时，队列再次满队。
+ 入队操作：
  - 1.首先入队操作首先判断队列是否已满，队列已满则不入队。
  - 2.其次，我们要注意到特殊情况，当队列由空队开始存入第一个数据时，以及last 等于 size-1 时，我们下一个数据入队会被存储在storge[0]的位置，此时需要令 last = 0，不要忘了如果 first 等于-1，同时要令 first = 0;
   - 3.其他情况++last，然后入队即可。
+ 出队操作：
  - 1.首先判断队列是否空，若为空，则不能出队。
  - 2.重点：当 first等于last 时，说明队列中只有一个元素，此时出队后队列为空，切记将 first ，last值 赋为-1，表示队列空。
  - 3.特殊情况：当 first 等于size-1 时，它处于storge数组尾部，事实上由于它是队列此状态下的首元素，队列的第二个元素是storge数组storge[0]，所以此时进行出队操作后，须将 first 的值设置为0。
  - 4.其他情况 直接出队，++first即可。
```C++

#ifndef _ARRAY_QUEUE_H
#define _ARRAY_QUEUE_H
 
#include <iostream>
using namespace std;
 
template<typename T, int size = 0>
class Queue{
public:
	Queue();
 
	bool is_empty()const;
	bool is_full()const;
 
	void enqueue(const T&);
	T dequeue();
 
	void traverse()const;
private:
	T storge[size];
	int first;
	int last;
};
 
template<typename T, int size>
Queue<T, size>::Queue()
{
	first = last = -1;
}
 
template<typename T, int size>
bool Queue<T, size>::is_empty()const
{
	return first == -1;
}
 
template<typename T, int size>
bool Queue<T, size>::is_full()const
{
	return first == 0 && last == size - 1 || last == first - 1;
}
 
template<typename T, int size>
void Queue<T, size>::enqueue(const T& elem)
{
	if(!is_full()){
		if(last == -1 || last == size -1){
			storge[0] = elem;
			last = 0;
			if(first == -1)
				first = 0;
		}
		else storge[++last] = elem;
	}
	else{
		cout << "Queue full." << endl;
		exit(EXIT_FAILURE);
	}
}
 
template<typename T, int size>
T Queue<T, size>::dequeue()
{
	if(is_empty()){
		cout << "Queue empty." << endl;
		exit(EXIT_FAILURE);
	}
 
	T tmp;
 
	tmp = storge[first];
	if(first == last)
		last = first = -1;
	else if(first == size - 1)
		first = 0;
	else ++first;
 
	return tmp;
}
 
template<typename T, int size>
void Queue<T, size>::traverse()const
{
	for(auto i=first; i<=last; ++i)
		cout << storge[i] << " ";
	cout << endl;
}
 
#endif


#include "array_queue.h"
 
int main()
{
	Queue<int, 3> queue;
	
	queue.enqueue(10);
	queue.enqueue(10);
+/-	queue.enqueue(10);
	cout << queue.is_full() <<endl;
	
	queue.traverse();
	
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	
	queue.is_empty();
	queue.traverse();
}
```
2.链表实现队列
```C++
template <class T>
class Queue {
private:
  struct Node {
    T data;
    Node *next;
  };
 
private:
  Node *head;
  Node *rear;
  int queueSize;
 
public:
  Queue() : head(NULL), rear(NULL), queueSize(0) { }
 
  ~Queue() {
    while (!empty())
      pop();
  }
 
  void push(const T &val) {
    Node *new_node = new Node;
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL && rear == NULL) {
      head = rear = new_node;
    } else {
      rear->next = new_node;
      rear = new_node;
    }
    ++queueSize;
  }
 
  void pop() {
    if (!empty()) {
      Node *temp = head;
      head = head->next;
      delete temp;
      --queueSize;
    }
  }
 
  T front() const {
    if (!empty())
      return head->data;
  }
 
  T back() const {
    if (!empty())
      return rear->data;
  }
 
  bool empty() const {
    return queueSize == 0;
  }
 
  int size() const {
    return queueSize;
  }
};
```
## 颜色分类

1.题目
```
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
注意:
不能使用代码库中的排序函数来解决这道题。
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
```
2.分析
+ 算法
  - 初始化0的最右边界：p0 = 0。在整个算法执行过程中 nums[idx < p0] = 0.
  - 初始化2的最左边界 ：p2 = n - 1。在整个算法执行过程中 nums[idx > p2] = 2.
  - 初始化当前考虑的元素序号 ：curr = 0.
  - While curr <= p2 :
    - 若 nums[curr] = 0 ：交换第 curr个和第 p0 个元素，并将两个指针都向右移。
    - 若 nums[curr] = 2 ：交换第 curr个和第 p2 个元素，并将p2指针左移 。
    - 若 nums[curr] = 1 ：将指针curr右移。
+ 注意，curr 左边全都是0/1的有序序列！
  - curr位置是0时，与左边的0位置交换，因为保证curr左边全是0/1, 所以交换过来的必然是0/1，状态维持住了；
  - curr位置是2时，交换后，curr不能移动，因为一移动，没法保证交换过来的是0/1；所以这里不移动；这时状态也维持住了
  - 只要我们保证curr左边的都是0,1，才移动，那么0都被放到左边，2都被放到右边，中间自然是1了。
+ 实现
```C++
void sortColors(vector<int>& nums) {
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;
    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
```
