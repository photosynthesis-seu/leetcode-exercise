# 目录
- [No.3 数组中的重复数字](#数组中的重复数字)
- [No.6 从尾到头打印链表](#从尾到头打印链表)
- [No.7 重建二叉树](#重建二叉树)
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
```
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
