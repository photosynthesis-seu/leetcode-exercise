# leetcode-exercise
# C++题目总结
```
已做题目：

No.4 寻找两个数组的中位数 No.5 最长回文子串 No.6 Z字形变换 No.7 整数反转 No.8 字符串转整数 No.9 回文整数的判断
No.11 盛最多水的容器 No.15 三数之和 No.21 合并两个有序链表 No.22 括号的生成 No.23 合并k个链表（哨兵节点、优先队列） NO.33 搜索旋转排序数组
No.42 接雨水问题 No.53 最大子序和 No.55 跳跃游戏 No.56 合并区间 No.72 编辑两个单词的距离
No.96 不同的二叉搜索树（动态规划）NO.95 不同的二叉搜索树II No.200 岛屿数量（经典动态规划、DFS、BFS题目！）
No.206 反转链表 NO.215 数组中第k个最大元素 No.300 最长递增子序列（经典动态规划）No.324 摆动排序
No.355 设计推特 No.435 无重叠区域（动态规划）
No.445 两数相加II（初始化一个链表的正确打开方式、栈实现高位先进，低位先出）
No.460-LFU缓存 No.466 统计重复个数（unordered_map） No.542 01矩阵分解
No.516 最长回文子序列 难-No.887 鸡蛋掉落 No.1111 有效括号的嵌套深度 No.1143 最长公共子序列 No.1162 地图分析

面试题13-机器人的运动范围（典型的DFS/BFS）面试题16.03 交点（主要考察你细不细致）面试01.07 旋转矩阵


剑指Offer No.38 字符串的排列
```
## No.1111 有效括号的嵌套深度

1.vector<int>等容器在声明时，**最好进行初始化** eg:vector<int> result(seq.size())；容器一般都有size()操作；
  
2.对于求字符串长度的函数：strlen/size/length的区别

方法一：调用length()或size()
```
string strTest="test";
strTest.length();			//结果为4
strTest.size();				//结果为4
```

方法二：转为C风格字符串，调用strlen()
```
strlen(strTest.c_str());	//结果为4
```
3.c++遍历字符串的三种方式

方法一：常规方式（下标+operator[])
```
int StrToInt1(string str)
{
    int value = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        value *= 10;
        value += str[i] - '0';
    }
    return value;
}
```
方法二：使用迭代器遍历字符串
```
int StrToInt2(string str)
    {
        //迭代器--在STL中，不破坏封装的情况下去访问容器
    int value = 0;
    string::iterator it = str.begin();//返回第一个位置的迭代器（类似于指针）
    while (it != str.end())//str.end()是最后一个数据的下一个位置
    {
        value *= 10;
        value += (*it - '0');
        it++;
    }
 ```
 方法三：新式for循环 （第三种字符串遍历方式源自于c++11）
 ```
 int StrToInt3(string str)
    {
        int value = 0;
        for (auto ch : str)//ch依次取的是str里面的字符,直到取完为止
        {
            value *= 10;
            value += (ch - '0');
        }
        return value;
    }
 ```


4.嵌套深度的计算方法：可以通过**栈实现括号匹配来计算**

  维护一个栈 s，从左至右遍历括号字符串中的每一个字符：如果当前字符是 (，就把 ( 压入栈中，此时这个 ( 的嵌套深度为栈的高度；如果当前字符是 )，此时这个 ) 的嵌套深度为栈的高度，随后再从栈中弹出一个 (。

  下面给出了括号序列 (()(())()) 在每一个字符处的嵌套深度：

括号序列   ( ( ) ( ( ) ) ( ) )

下标编号   0 1 2 3 4 5 6 7 8 9

嵌套深度   1 2 2 2 3 3 2 2 2 1 

  只要在遍历过程中，我们保证栈内一半的括号属于序列 A，一半的括号属于序列 B，那么就能保证拆分后最大的嵌套深度最小，是当前最大嵌套深度的一半。要实现这样的对半分配，我们只需要把奇数层的 ( 分配给 A，偶数层的 ( 分配给 B 即可。对于上面的例子，我们将嵌套深度为 1 和 3 的所有括号 (()) 分配给 A，嵌套深度为 2 的所有括号 ()()() 分配给 B。
  
 ## No.4 寻找两个数组的中位数
 
 1.通过**割(Cut)算法**，把有序数组分成左右两个部分，割的左右会有两个元素，分别是左边最大值和右边最小值。
 ```
 LMax= Max(LeftPart)，RMin = Min(RightPart)
 Ci为第i个数组的割。
 ```
 最终目的为：
 ```
 LMax1<=RMin1，LMax2<=RMin2;
 LMax1<=RMin2，LMax2<=RMin1;
 ```
 2.通过将数组大小隐性X2+1的方法，将两个数组的长度强制转化为偶数。
 ```
 LMaxi = (Ci-1)/2 位置上的元素;
 RMini = Ci/2 位置上的元素;
 ```
 
 ## No.5 最长回文子串
 1.反转一个字符串
 ```
 string s;
 string reverse_s = s;
 std::reverse(reverse_s.begin(),reverse_s.end());//可以将reverse_s反转；
 ```
 2.初始化二维vector
 ```
 int length = s.length();
 vector<vector<int>> dp(length,vector<int>(length));
 ```
 3.输出一个字符串的子串
 ```
 int start = 0;//子串开始位置
 int sub_length = 5;//子串长度
 s.substr(start,sub_length)；//substr为子串函数
 ```
 4.动态规划
 ```
 //从长度为3的子字符串开始动态寻找回文串
        for(int l=3;l<length;l++){
            for(int i = 0; i<length-l+1;i++){
                int j = i+l-1;
                //分析：dp[i][j]其实就是表示从i到j的子串是不是回文串（因为是从长度为2、3的子串开始累积往更长的子串计算的）
                //分析：这里的dp[i+1][j-1]就是状态转移，如果在这个位置的上一个长度的子串是回文串，那么就可以继续累积下去，看更长的子串是不是回文串。
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    start = i;
                    sub_length = l;
                }
            }
        }
 ```
 5.**中心拓展法**
 
 回文子串以中心字符为基准左右对称。那么可以根据以中心两个字符为基准（偶数串）或以中心一个字符为基准（奇数串），来向两边进行拓展。
 
 通过遍历字符串的2n-1种可能性：n（奇数串，每个字符都可以是中心）+n-1（偶数串，以字符串的空隙为中心）= 2n-1，来确定最长回文子串
 
 ```
  for(int i=0;i<len;i++)
        {
            int len1=expendaroundcenter(s,i,i);//一个元素为中心
            int len2=expendaroundcenter(s,i,i+1);//两个元素为中心
            mlen=max(max(len1,len2),mlen);
            if(mlen>end-start+1)
            {
                start=i-(mlen-1)/2;
                end=i+mlen/2;
            }
        }
        return s.substr(start,mlen);

 ```
 回文字符串的判断方法：
 ```
  int expendaroundcenter(string s,int left,int right)
    //计算以left和right为中心的回文串长度
    {
        int L=left;
        int R=right;
        while(L>=0 && R<s.length() && s[R]==s[L])
        {
            L--;
            R++;
        }
        return R-L-1;
    }
 ```
 ## No.206 反转链表
 
 **做链表题目一定要多画图！**
 
 1.单链表的简单声明
 
 ```
  struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 ```
 2.双指针的迭代思路
 
 (1)对于函数LListNode* reverseList(ListNode* head)，返回head即可；
 
 (2)ListNode* cur = NULL;ListNode* pre = head;是两个链表，顺便当双指针用；
 
 ```
 ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        //双指针的思想，一个一个迭代遍历，改变指向。但是注意！cur、pre本身都是链表！！
        ListNode* cur = NULL;
        ListNode* pre = head;
        while(pre != NULL){
            ListNode* temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;//cur逐渐从NULL一步一步倒推，变成head链表的反转。head链表本身没有改变。
        }
        return cur;//注意！返回的是cur！不是*cur，因为函数类型本身就是ListNode*了
    }
 ```
## No.21 合并两个有序链表

1.合并有序链表时用两个链表的指针分别比较每一个节点的大小，然后申请一个新链表存储比较后每一个比较小的节点。

**注意!!** 不需要考虑两个节点值相等的情况，因为相等时随便让一个节点进入，然后留下另一个节点和之后的节点比较，它最终还是会进入链表的。

2.创建一个链表，并简单初始化一个值。

注意一个技巧：最后的结果是从result链表第二个节点开始的，这样做可以每次从result->next添加节点。
```
ListNode* result = new ListNode(1);
ListNode* res = result;//最后的结果是从result链表第二个节点开始的，这样做可以每次从result->next添加节点
```
3.注意这里的判断条件必须用&&，如果用或的话，NULL无法和另一个链表节点的值比大小。
```
while(l1 != NULL && l2 != NULL){
//比较两个链表节点值的大小//
}
result->next = l1 == NULL? l2:l1;//在这一步再将更长一些的链表补在result后面
```
## 剑指Offer No.38 字符串的排列

1.**set的使用**

(1)set<T> 容器保存 T 类型的对象，而且保存的对象是唯一的（一般来说不可以重复）。同时保存的元素是有序的（平衡二叉树）
  
(2)set中添加元素用insert();删除元素用erase();访问元素可以用auto iter = s.find("a")

  -----待完善
  
2.**vector和set之间数据的转化方法**
```
vector<string> result;//最终输出结果
set<string> res;//使用set的性质去除重复字符串排列
result = vector<string>(res.begin(),res.end());
```
3.void函数虽然没有返回值，但是**不要忘记最后return ！！**

4.函数形参中的引用问题

```
void paixu(std::string s, int start, std::set<std::string> &res) {
    // 回溯结束条件
    if(start == s.size()){
        res.insert(s);
        return;
    }
```
在函数paixu里面，一定要注意参数中set<string> &res，res一定要是引用的形式，因为函数本身没有返回值，res作为形参生命周期结束就会被销毁，
  
只有使用引用才能使得res的值在递归的时候不断更新。

5.**回溯算法（递归实现）**

 字符串的排列和数字的排列都属于回溯的经典问题
  
 回溯算法框架：解决一个问题，实际上就是一个决策树的遍历过程：
 
 (1)路径：做出的选择
 
 (2)选择列表：当前可以做的选择
 
 (3)结束条件：到达决策树底层，无法再做选择的条件
 
 伪代码：
 ```
 result = []
 def backtrack(路径，选择列表):
      if 满足结束条件：
          result.add(路径)
         return
      for 选择 in 选择列表:
          做选择
          backtrack(路径，选择列表)
          撤销选择
 ```
 递归函数通常都是void类型的，所以要注意之前提到的问题。
 
  **核心是for循环中的递归，在递归调用之前“做选择”，在递归调用之后“撤销选择”。**
  
6.基于交换法的回溯算法（本题）

(1)思路
```
 * [a, [b, c]]
 * [b, [a, c]] [c, [b, a]]
 *
 * 如上，对字符串"abc"分割，每次固定一个字符为一部分，
 * 其他字符为另一部分，再将固定字符与其他字符进行交换，
 * 依次遍历每个字符，再进行回溯递归。
```
**(2)具体实现细节**
```
/*
     * 回溯函数
     * 使用set函数对字符串字符进行去重，
     * 使用swap函数交换两个字符
     * */
void paixu(std::string s, int start, std::set<std::string> &res) {
    // 回溯结束条件
    if(start == s.size()){
        res.insert(s);
        return;
    }

    for(int i = start; i < s.size(); i++){
        // 做选择
        std::swap(s[i], s[start]);
        // 进入下一次决策树
        paixu(s, start+1, res);
        // 撤销选择
        std::swap(s[i], s[start]);
    }
}
```
## No.8 字符串转整数

1.C++中ostringstream、istringstream、stringstream三个类

istringstream类用于执行C++风格的串流的输入操作; ostringstream类用于执行C风格的串流的输出操作; strstream类同时可以支持C风格的串流的输入输出操作。

**istringstream对象 可以绑定一行字符串，然后以空格为分隔符把该行分隔开来**

```
#include<iostream>  
#include<sstream>        //istringstream 必须包含这个头文件
#include<string>  
using namespace std;  
int main()  
{  
    string str="i an a boy";  
    istringstream is(str);  
    string s;  
    while(is>>s)  
    {  
        cout<<s<<endl;  
    }  
} 
```
输出是
```
i
am
a
boy
```
2.uordered_map
用来存储键和值，面对嵌套vector时的访问，可以用下面的例子来展示：
```
unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };//键是string，值是vector<string>
state = table[state][get_col(c)];//使用两个下表来进行访问，第一个访问键，第二个访问值中的不同元素
```
3.**判断字符串中字符为空格和数字的方法**

(1)方法一：使用isspace()和isdigit()函数
```
char c;
int i = isspace(c);//是否为空格的判断函数
int j = isdigit(c);//是否为数字的判断函数
```
(2)方法二：直接判断
```
for(int i = 0; i<str.length(); i++){
    if(str[i] == " "){...}//判断是否为空格
    if(str[i] >= '0'&& str[i] <= '9'){...}//判断是否为整数
}
```
关注**判断字符是否为整数的方法：str[i] >= '0'&& str[i] <= '9'**

4.字符串转数字
```
int digit =str[i] - '0';
```
## No.15 三数之和

**此题自己的暴力递归方法存在一些问题，待解决**

1.vector容器中所有元素求和的函数：accmulate()
```
vector<int> res;
int sum = accumulate(res.begin(),res.end(),0);
```
2.vector中的pop操作，直接就是res.pop_back();

**3.三数之和/若干数之和的问题典型解决思路**

   **双指针！！+排序！！**
   
算法流程：

(1). 特判，对于数组长度*n*，如果数组为*null*或者数组长度小于3，返回[]。

(2). 对数组进行排序。

(3). 遍历排序后数组：

  * 若*nums[i]>0*：因为已经排序好，所以后面不可能有三个数加和等于0，直接返回结果。
    
  * 对于重复元素：跳过，避免出现重复解。
    
  * 令左指针*L=i+1*，右指针*R=n−1*，当*L<R*时，执行循环：
    
    + 当*nums[i]+nums[L]+nums[R]==0*，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将L++,R-- ，寻找新的解。
      
    + 若和大于 0，说明*nums[R]* 太大，R 左移。
      
    + 若和小于 0，说明*nums[L]* 太小，L 右移。

4.vector中sort函数可以实现排序

sort(std::begin(numbers), std::end(numbers), std::greater<>());没有第三个参数默认升序排列

## No.42 接雨水问题

1.思路分析：

对于数组中的每个元素，我们找出下雨后水能达到的最高位置，等于两边最大高度的较小值减去当前高度的值。

+ 找到数组中从下标 i 到最左端最高的条形块高度 *left_max*。
+ 找到数组中从下标 i 到最右端最高的条形块高度 *right_max*。
+ 扫描数组 *height* 并更新答案：
  - 累加 *result += min(Left_Max[i],Right_Max[i]) - height[i]*
  
2.动态规划的实现（**注意利用备忘录！！**）

```
int trap(vector<int>& height) {
        if(height.size() == 0 ||height.size() == 1||height.size() == 2){
            return 0;
        }
        int result = 0;
        int size = height.size();
        vector<int>Left_Max(size);//动态规划，两个备忘录
        vector<int>Right_Max(size);//存放每个柱子左边和右边的最大高度
        Left_Max[0] = height[0];
        for(int i = 1; i < size-1;i++){
                Left_Max[i] = max(Left_Max[i-1],height[i]);
            }//注意算柱子左边最高的柱子时，是从1开始遍历到size-1
        Right_Max[size-1] = height[size-1];
        for(int i = size - 2; i > 0; i--){
                Right_Max[i] = max(Right_Max[i+1],height[i]);
            }//柱子右边最高的柱子时是从size-2开始遍历的，i--。要注意左右区分
        for(int i = 1;i < size-1;i++ ){
        result += min(Left_Max[i],Right_Max[i]) - height[i]; //木桶效应
        }
         return result;
    }  
```

## No.72 编辑两个单词的距离

1.题目要求：
```
输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
```
2.分析（**使用动态规划！！**）

我们可以把大问题拆分为小问题，**定义cost[i][j]** 为word1的前i个字符变为word2的前j个字符时需要消耗的步骤。我们假定了此题单词的转化是按顺序进行的！

+ 替换的情况：当word1中的前i-1个就可以变换为word2中的前j-1个，那么我们只要根据word1中的第i个是否等于word2中的第j个字符进行判断，如果相等，那么cost[i][j]=cost[i-1][j-1];否则，cost[i][j]=cost[i-1][j-1]+1,加的1就是我们将word1中第i个字符替换为word2中第j个的消耗。
+ 删除的情况：当word1中的前i-1个就可以变换为word2中的前j个时，我们需要将word1中的第i个字符删除，cost[i][j]=cost[i-1][j]+1
+ 增加的情况：当word1中的前i个可以变换为word2中的前j-1个时，我们需要将word1中的第i个字符后面增加一个，cost[i][j]=cost[i][j-1]+1
+ **注意**，cost数组索引均是从1开始，而word中索引是0开始的，所以word1[i-1] == word2[j-1]，就是在判断word1中的第i个字符是否等于word2中第j个字符。

所以，cost[i][j]取上列的最小值即可。

3.展示horse如何转化为ros

![image](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/images/QQ%E5%9B%BE%E7%89%8720200404171329.png)

4.实现
```
int minDistance(string word1, string word2) {
        // 对于每个状态下，都有三种选择，替换、删除、插入
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> cost(m+1, vector<int>(n+1,0));
        // 必须具有0->0 ，消耗为0，这里索引是从1开始的。
        // word1:1..m  ; word2:1..n
        for(int i=0;i<=m;i++){
            cost[i][0] = i;// word2是0，那么word1中的i个要全部删除
        }
        for(int j=0;j<=n;j++){
            cost[0][j] = j;// word1是0，那么word1增加每一个word2的字符个数j
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int min_ = 1999;
                if(word1[i-1] == word2[j-1]){
                    // 因为i和j是从1开始计数，对于word索引要-1
                    min_ = cost[i-1][j-1];
                }
                min_ = min(min_, cost[i-1][j-1]+1);// i替换j
                min_ = min(min_, cost[i-1][j]+1);// 删除i
                cost[i][j] = min(min_, cost[i][j-1]+1);// 增加
            }
        }
        return cost[m][n];
    }
```

## 难-No.887 鸡蛋掉落

1.**典型的动态规划**

+ 对动态规划问题，直接套框架即可：这个问题有什么「状态」，有什么「选择」，然后穷举。

+ 「状态」很明显，就是当前拥有的鸡蛋数 K 和需要测试的楼层数 N。随着测试的进行，鸡蛋个数可能减少，楼层的搜索范围会减小，这就是状态的变化。

+ 「选择」其实就是去选择哪层楼扔鸡蛋。线性扫描选择一层层向上测试。不同的选择会造成状态的转移。

  明确了「状态」和「选择」，动态规划的基本思路就形成了：肯定是个二维的 dp 数组或者带有两个状态参数的 dp 函数来表示状态转移；外加一个 for 循环来遍历所有选择，择最优的选择更新状态：
```
class Solution {
    public int superEggDrop(int K, int N) {
        return Solution.recursive(K, N);
    }
    
    public static int recursive(int K, int N) {
        if (N == 0 || N == 1 || K == 1) {
            return N;
        }

        int minimun = N;
        for (int i = 1; i <= N; i++) {
            int tMin = Math.max(Solution.recursive(K - 1, i - 1), Solution.recursive(K, N - i));
            minimun = Math.min(minimun, 1 + tMin);
        }
        return minimun;
    }
};
```
2.一种暴力的带备忘录的动态规划
```
for (int k = 2; k <= K; k++) { // 遍历所有鸡蛋、楼层高度可能，然后使用备忘录记录每种可能的最优解
            for (int n = 1; n <= N; n++) {
                int tMinDrop = N * N;
                for (int x = 1; x <= n; x++) {
                    tMinDrop = Math.min(tMinDrop, 1 + Math.max(middleResults[k - 1][x - 1], middleResults[k][n - x]));
                }
                middleResults[k][n] = tMinDrop;//备忘录记录结果
            }
        }

        return middleResults[K][N];
```
3.一种使用二分查找+动态规划的方法：

![image](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/images/12.png)
```
class Solution {
    Map<Integer, Integer> cache = new HashMap<>();
    
    public int superEggDrop(int K, int N) {
        if (N == 0)
            return 0;
        else if (K == 1)
            return N;

        Integer key = N * 1000 + K; // K <= 100
        if (cache.containsKey(key))
            return cache.get(key);

        int low = 1, high = N;
        while (low + 1 < high) {
            int middle = (low + high) / 2;
            int lowVal = superEggDrop(K - 1, middle - 1);
            int highVal = superEggDrop(K, N - middle);

            if (lowVal < highVal)
                low = middle;
            else if (lowVal > highVal)
                high = middle;
            else
                low = high = middle;
        }
        int minimum = 1 + Math.min(
                Math.max(superEggDrop(K - 1, low - 1), superEggDrop(K, N - low)),
                Math.max(superEggDrop(K - 1, high - 1), superEggDrop(K, N - high))
        );

        cache.put(key, minimum);

        return cache.get(key);
    }
};
```
## No.460-LFU缓存

1.首先需要定义一个缓存的数据结构
```
struct Node {
    int cnt;//缓存使用频率
    int time;//缓存使用时间
    int key, value;
    
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
```
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
    }......
 }
```
## No.6 Z字形变换

1.可以使用 min(numRows,len(s)) 个列表来表示 Z 字形图案中的非空行。

从左到右迭代 s，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。

只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。

2.一种遍历字符串和字符串vector中字符串的方法：

```
string s;
vector<string> rows;
for (char c : s) {...}
for (string row : rows){...}
```

2.具体实现
```
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
```
## No.7 整数反转

1.字符串转整数的函数

C 库函数 int atoi(const char *str) 把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。

**Linux内核中只有atoi()函数，被包含在stdlib.h头文件中，而没有itoa()函数**

2.整数转字符串的函数

char *itoa( int value, char *string,int radix);

原型说明：value：欲转换的数据;string：目标字符串的地址。radix：转换后的进制数，可以是10进制、16进制等。

**itoa()并不是一个标准的C函数**，它是Windows特有的.如果要写跨平台的程序，标准库中有sprintf，用法跟printf类似：
```
char str[255];
sprintf(str, "%x", 100); //将100转为16进制表示的字符串。
```
## No.9 回文整数的判断

1.核心思路

不要转成字符串，反转以后再转回整数。考虑将数字本身反转，然后将反转后的数字与原始数字进行比较，如果它们是相同的，那么这个数字就是回文。
但是，如果反转后的数字大于int.MAX，将遇到整数溢出问题。

**为了避免数字反转可能导致的溢出问题**，考虑只反转数字的一半。毕竟，如果该数字是回文，其后半部分反转后应该与原始数字的前半部分相同。

例如，输入 1221，我们可以将数字 “1221” 的后半部分从 “21” 反转为 “12”，并将其与前半部分 “12” 进行比较，因为二者相同，我们得知数字 1221 是回文。

2.实现的细节
```
 int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber/10;
    }
```
## No.300 最长递增子序列（经典动态规划）

1.关键在于(1)如何定义dp[i]是什么，也就是确定最优子结构；(2)如何建立状态转移方程；

同时注意本题是求递增子序列，不是子列。因此递增数字的下标不一定连续，只要保证递增即可。

这个是[最长递增子序列](https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E8%AE%BE%E8%AE%A1%EF%BC%9A%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.md)的解答

2.我们可以看到：

+ 定义：dp[i] 表示以 **nums[i] 这个数结尾的最长递增子序列的长度**，这样设计可能算法上有点重叠，但是比较简练，且每个子问题肯定是最优解。
+ 状态转移：例如nums={1,4,3,4,2,3}，假设已知dp[0]~dp[4] **类似数学归纳法**,求dp[5]。既然是递增子序列，nums[5]=3,我们只要找到前面那些结尾比 3 小的子序列，然后把 3 接到最后，就可以形成一个新的递增子序列，而且这个新的子序列长度加1。

当然，可能形成很多种新的子序列，但是我们只要最长的，把最长子序列的长度作为 dp[5] 的值即可。

3.代码实现
```
public int lengthOfLIS(int[] nums) {
    int[] dp = new int[nums.length];
    // dp 数组全都初始化为 1
    Arrays.fill(dp, 1);
    for (int i = 0; i < nums.length; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) 
                dp[i] = Math.max(dp[i], dp[j] + 1);
        }
    }
    
    int res = 0;
    for (int i = 0; i < dp.length; i++) {
        res = Math.max(res, dp[i]);
    }
    return res;
}
```
4.循环里面第二个循环是for (int j = 0; j < i; j++)，因为不知道也不要计算j>i时的情况。

此时的dp[j]不知道，且如果nums[j]大于nums[i]，因为是求递增子序列的缘故，自会有dp[j]在之后补充。

## 面试01.07 旋转矩阵

1.关于利用vector<vector<int>>  vec定义一个二维矩阵，如果想获取vec的行数和列数。可以使用：

vec.size()和 vec[0].size()来分别获取行数和列数。

2.**一定要注意二维vector初始化后的push_back问题**
```
void rotate(vector<vector<int>>& matrix) {
        int N = matrix[0].size();
        if(N==0 || N==1){
            return;
        }
        vector<vector<int>> res(N,vector<int>(N));
        //vector<vector<int>> res;
        for(int i = 0; i<N; i++){
            for(int j = N-1; j>=0; j--){
                //res[i].push_back(matrix[j][i]);//必须用下面代码，此行代码的问题是由于已经初始化，push_back会从res[0][N]开始装填，导致前面res[0][0]~res[0][N-1]全是0.
                res[i][N-1-j]=matrix[j][i];
            }
        }
        //matrix.clear();
        matrix = res;
    }
```
## No.11 盛最多水的容器
```
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
```

1.典型思路是**使用双指针!**

+ 算法流程： 设置双指针i,j分别位于容器壁两端，根据规则移动指针（后续说明），并且更新面积最大值 res，直到 i == j 时返回 res。

+ **指针移动规则与证明： 每次选定围成水槽两板高度h[i],h[j]中的短板，向中间收窄1格。** 以下证明：

  - 设每一状态下水槽面积为S(i,j),(0<=i<j<n)，由于水槽的实际高度由两板中的短板决定，则可得面积公式S(i, j) = min(h[i], h[j]) × (j - i)
  - 在每一个状态下，无论长板或短板收窄1格，都会导致水槽 底边宽度−1：
    - 若向内移动短板，水槽的短板min(h[i],h[j]) 可能变大，因此水槽面积S(i,j) 可能增大。
    - 若向内移动长板，水槽的短板min(h[i],h[j]) 不变或变小，下个水槽的面积一定小于当前水槽面积。
+ 因此，向内收窄短板可以获取面积最大值。换个角度理解：

  - 若不指定移动规则，所有移动出现的S(i,j 的状态数为C(n,2)，即暴力枚举出所有状态。
  
  - 在状态S(i,j)下向内移动短板至S(i+1,j)(假设 h[i] < h[j]),则相当于消去了 {S(i, j - 1), S(i, j - 2), ... , S(i, i + 1)}S(i,j−1),S(i,j−2),...,S(i,i+1) 状态集合。而所有消去状态的面积一定<=S(i,j)：
    - 短板高度：相比S(i,j) 相同或更短（<= h[i]）
    - 底边宽度：相比S(i,j) 更短。因此所有消去的状态的面积都S(i,j)。
通俗的讲，我们每次向内移动短板，所有的消去状态都不会导致丢失面积最大值 。

2.算法实现

**双指针算法，关键点在于如何制定双指针的移动规则**
```
class Solution {
public:
    int maxArea(vector<int>& height) {
    int res = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j) {
        int area = (j - i) * min(height[i], height[j]);
        res = max(res, area);
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return res;
}
};
```
## No.1143 最长公共子序列

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
```
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
## 面试题13-机器人的运动范围（典型的DFS/BFS）

1.题目描述
 ```
 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
 ```
2.关于队列queue

(1)队列的声明： queue<pair<int,int> > Q;//用来存放广度优先遍历的顺序（先进先出）

(2)队列中添加元素：Q.push(make_pair(0, 0));

(3)队列弹出元素，以及智能定义队列中的pair：
```
 auto [x, y] = Q.front();//队列顶端只能用front
 Q.pop();
```    
3.数为求和算法（**小技巧**）
 
设一数字 xx ，向下取整除法符号/，求余符号⊙，则有：
+ x⊙10 ：得到 x 的个位数字；
+ x/10 ： 令 x 的十进制数向右移动一位，即删除个位数字。
因此，可通过循环求得数位和，代码如下：
```
// 计算 x 的数位之和（1步是模10，2步是除以10，注意这个技巧）
    int get(int x) {
        int res=0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
```
4.搜索方向简化：

数位和特点： 根据数位和增量公式得知，数位和每逢进位突变一次。
+ 解的三角形结构：
  - 根据数位和特点，矩阵中 满足数位和的解 构成的几何形状形如多个 等腰直角三角形 ，每个三角形的直角顶点位于0,10,20,... 等数位和突变的矩阵索引处 。
  - 三角形内的解虽然都满足数位和要求，但由于机器人每步只能走一个单元格，而三角形间不一定是连通的，因此机器人不一定能到达，称之为 不可达解 ；同理，可到达的解称为 可达解 （本题求此解） 。
+ 结论： 根据可达解的结构，易推出机器人可仅通过**向右和向下移动，访问所有可达解** 
  - 三角形内部： 全部连通，易证；
  - 两三角形连通处： 若某三角形内的解为可达解，则必与其左边或上边的三角形连通（即相交），即机器人必可从左边或上边走进此三角形。
  
5.广度优先算法

+ BFS/DFS ： 两者目标都是遍历整个矩阵，不同点在于搜索顺序不同。DFS 是朝一个方向走到底，再回退，以此类推；BFS 则是按照“平推”的方式向前搜索。
+ BFS 实现： 通常利用队列实现广度优先遍历。
算法解析：
+ 初始化： 将机器人初始点make_pair(0,0) 加入队列 queue ；
+ 迭代终止条件： queue 为空。代表已遍历完所有可达解。
+ 迭代工作：
  - 单元格出队： 将队首单元格的索引弹出，将其下方、右方元素作为当前搜索单元格。
  - 判断是否跳过： 若 ① 行列索引越界 或 ② 数位和超出目标值 k 或 ③ 当前元素已访问过 时，执行 continue 。
  - 标记当前单元格 ：将单元格索引chess[x],[y]赋值1，代表此单元格可以被访问。
  - 单元格入队： 将当前可以被访问的下方、右方单元格的索引加入queue ；结果++
  - 返回值：返回结果。
```
int movingCount(int m, int n, int k) {
        if (!k) return 1;
        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        queue<pair<int,int> > Q;//用来存放广度优先遍历的顺序（先进先出）
        vector<vector<int> > vis(m, vector<int>(n, 0));//二维数组用来存放机器人能否访问的结果（0 or 1）
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();//队列顶端只能用front
            Q.pop();
            for (int i = 0; i < 2; ++i) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }
```
## No.516 最长回文子序列

1.题目
```
给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000
```
一道典型的动态规划问题！

2.实现

[详细解答见此文章](https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E5%AD%90%E5%BA%8F%E5%88%97%E9%97%AE%E9%A2%98%E6%A8%A1%E6%9D%BF.md)
```
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
## No.22 括号的生成

1.题目描述：
```
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
输入: 3
输出:
["((()))","(()())","(())()","()(())","()()()"]
```

2.注意**string类型添加和删除元素,和vector不一样**：
```
string s;
s.push_back('s');
s.pop_back('s');
```

3.如何判断生成的括号是否有效？

思路核心在于左括号与右括号数量一定要相等，并且**从左往右遍历字符串时，右括号数量一定不能多于左括号数量**,经典算法如下：
```
bool decision(string cur){
        int balance = 0;
        for(int i = 0;i<cur.size();i++){
            if(cur[i] == '('){
                balance++;
            }
            else {
                if(balance<0) return false;
                balance--;
            }
        }
        return balance == 0;
    }
```
4.使用递归算法的实现（偏暴力）

可以直接看代码，注意递归的跳出条件、如何遍历每一种可能性；

```
void useful(vector<string>& res,string& cur,int left,int right,int n){
        if(cur.size() == 2*n){
            //if(decision(cur)){
                res.push_back(cur);
            }//这个判断可以不要，因为后面的if相当于实现了是否是有效括号的判断
            return;
        }
        if(left<n){
            cur += '(';
            useful(res,cur,left+1,right,n);
            cur.pop_back();//关注string类型的元素添加和删除
        }
         if(right<left){
            cur += ')';
            useful(res,cur,left,right+1,n);
            cur.pop_back();
        }
        return;
    }
```
5.**使用二叉树结构的DFS**

(1)这种方法和上面的代码异曲同工，利用了二叉树结构，更简便一些，详细请看[这篇解析](https://leetcode-cn.com/problems/generate-parentheses/solution/ru-men-ji-bie-de-hui-su-fa-xue-hui-tao-lu-miao-don/)

(2)**把有效括号的判断，简化成了这么短短的几句！ if (rc > lc || lc > n || rc > n) return;if (lc == rc && lc == n)...**

(3)注意函数参数是否引用的区别！dfs(vector<string>& res, string cur, int n, int lc, int rc)和useful(vector<string>& res,string& cur,int left,int right,int n)
  
 用operator+的时候, 是按值传入的, 沒有改变cur. 而push_back()时, 改变了cur。 
```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int lc = 0, rc = 0;
        dfs(res, "", n, lc, rc);
        return res;
    }
    void dfs(vector<string>& res, string path, int n, int lc, int rc) {
        if (rc > lc || lc > n || rc > n) return;
        if (lc == rc && lc == n) {
            res.push_back(path);
            return;
        }
        dfs(res, path + '(', n, lc + 1, rc);
        dfs(res, path + ')', n, lc, rc + 1);
        return;
    }
};
前面算法这么改，竟然和他一样
void backtrack(vector<string>& ans, string cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            //cur.push_back('(');
            backtrack(ans, cur+'(', open + 1, close, n);
            //cur.pop_back();
        }
        if (close < open) {
            //cur.push_back(')');
            backtrack(ans, cur+')', open, close + 1, n);
            //cur.pop_back();
        }
    }
```
## No.96 不同的二叉搜索树（动态规划）

1.题目
```
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
示例:
输入: 3 输出: 5
解释: 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3
```
2.分析
+ 假设 n 个节点存在的二叉排序树的个数是 G(n) ，令 f(i) 为以 i 为根的二叉搜索树的个数，则：
  - G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)
+ 当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，则
  - f(i) = G(i-1) * G(n-i)
+ 综合两个公式可以得到 **卡特兰数** 公式：
  - G(n) = G(0) * G(n-1)+G(1) * (n-2)+...+G(n-1) * G(0)
  
3.实现
```
int numTrees(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
```
## NO.95 不同的二叉搜索树II

1.题目
```
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。(参考No. 96)
```
2.分析

+ 从序列 1 ..n 中取出数字 i，作为当前树的树根。于是，剩余 i - 1 个元素可用于左子树，n - i 个元素用于右子树。
如 前文所述，这样会产生 G(i - 1) 种左子树 和 G(n - i) 种右子树，其中 G 是卡特兰数。
+ 对序列 1 ... i - 1 重复上述过程，以构建所有的左子树；然后对 i + 1 ... n 重复，以构建所有的右子树。

这样，我们就有了树根 i 和可能的左子树、右子树的列表。

3.实现
```
vector<TreeNode*> helper(int start,int end){
        vector<TreeNode*> ret;
        if(start > end)
            ret.push_back(nullptr);
        
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = helper(start,i-1);
            vector<TreeNode*> right = helper(i+1,end);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ret.push_back(root);
                }
            }
        }
        return ret;
```
## No.151 反转字符串里的单词

1.题目
```
给定一个字符串，逐个翻转字符串中的每个单词。
输入: "  hello world!  "
输出: "world! hello"
输入: "a good   example"
输出: "example good a"
```
2.**stack栈的一些操作**
```
empty() 堆栈为空则返回真；
pop() 移除栈顶元素 ;pop_back移除栈尾元素；
push() 在栈顶增加元素 （增加）；
size() 返回栈中元素数目；
top() 返回栈顶元素，不删除（获取）；
```
**需要注意的是**当字符串为空时""，它也可以被压入堆栈，并且占用一个堆栈内存空间，这一点一定要注意！！

3.实现简单来说是利用栈后进先出的特点实现，难点在于如何排除空格的影响。具体代码如下：
```
tring reverseWords(string s) {
        stack<string> res;
        string cur;
        string result;
        int length = s.size();
        if(length == 0){
            return result = "";
        }
        for(int i = 0;i<length;i++){
            if(s[i] == ' '){
                continue; 
            }
            else{
                cur += s[i];
            }
            if(s[i] != ' '&&s[i+1] == ' '){
                res.push(cur);
                cur = "";
            }
        }
        //res.push(cur);
        if(cur != ""||res.size() == 0){
            res.push(cur);
         }//这个判断是为了应对s="   "
        while(!res.empty()){
            string temp = res.top()+" ";
            result += temp;
            res.pop();
        }
        result.pop_back();//可以把字符串末尾的空格pop掉。
        return result;
    }
```
## 面试题16.03 交点（主要考察你细不细致）

1.题目
```
给定两条线段（表示为起点start = {X1, Y1}和终点end = {X2, Y2}），如果它们有交点，请计算其交点，没有交点则返回空值。
要求浮点型误差不超过10^-6。若有多个交点（线段重叠）则返回X值最小的点，X坐标相同则返回Y值最小的点。
示例输入：
line1 = {0, 0}, {1, 0}
line2 = {1, 1}, {0, -1}
输出： {0.5, 0}
```
2.分析

+ 这道题主要就是考察细不细致，首先进行预处理：
```
预处理：先对线段端点进行排序。每条线段的start中，存储x较小的，x相同时，存y小的;
当斜率不存在时： 1). 两条线段斜率都不存在 2). 有一条线段斜率存在
当斜率均存在时：1) 两条线段斜率相等 2) 两条线段斜率不相等
```
+ **利用直线方程求交点**：
```
//求解斜率与纵截距
 vector<double> getLine(vector<int> st, vector<int> ed) {
        double k = (double) (st[1] - ed[1]) / (st[0] - ed[0]), b = st[1] - k * (double) st[0];
        return {k, b};
    }
// 求交点
 double x = (line2[1] - line1[1]) / (line1[0] - line2[0]), y = line1[0] * x + line1[1];
```
+ 具体**分情况讨论**：
```
1. 斜率不存在: eg. x = a;
   1.1 两条线段斜率都不存在
      1.1.1 横坐标不等，两线段平行，无解；
      1.1.2 横坐标相等，判断两条线段是否有重合部分，若有返回纵坐标较小的点。
   1.2 有一条线段斜率存在
      1.2.1 line1斜率存在，求交点，判断范围；
      1.2.2 line2斜率存在，求交点，判断范围。
2. 斜率均存在
   2.1 两条线段斜率相等
      2.1.1 是同一条直线，判断两条线段是否有重合部分，若有返回纵坐标较小的点；
      2.1.2 不是同一条直线，则两条线段平行，无解。
   2.2 两条斜率不相等
       正常求解。
```
3.利用数学技巧的通用解法

[确定两点之间线段的公式模型和算法](https://leetcode-cn.com/problems/intersection-lcci/solution/wo-jue-de-wo-yi-jing-hen-nu-li-liao-ke-yi-jiao-zhu/)

## NO.215 数组中第k个最大元素

1.题目
```
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```
2.注意一维vector的初始化和重新赋值：
```
vector<int> res(n+1,0);
res[i] = res[i-1]+res[i-2];
```
3.**排序函数sort()**

**关注** sort() 只能接受 array、vector、deque 或标准数组中的元素。

sort()默认是升序排列，可以使用great()参数实现降序排序。
```
 int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(),nums.end(),greater());
        return nums[k-1];
    }
```
## NO.33 搜索旋转排序数组

1.题目
```
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
    输入: nums = [4,5,6,7,0,1,2], target = 0
    输出: 4
```
2.分析

+ 这是一道典型的**二分搜索**题目
+ 关键在于如何确定每次二分查找的边界，可以这样考虑，nums[left]~nums[mid]和nums[mid]~nums[right]必然有一个区间是完全升序排列！
  - nums[left] <= nums[mid]，那么**必然nums[left]~nums[mid]是升序排列**
    - 如果target在两者之间，那么right = mid-1;
    - 如果target不在两者之间，那么left = mid+1;
  - 否则，nums[mid]~nums[right]为升序排列
    - 如果target在两者之间，那么left = mid+1;
    - 如果target不在两者之间，那么right = mid-1;
+ 这种方法巧妙地实现了每次将左右区间中的一边转化到mid！
3.实现
```
 public int search(int[] nums, int target) {
        int left = 0;int right = nums.length-1;int mid = left + (right-left)/2;
        while(left <= right){
            if(nums[mid] == target){
                return mid;
            }
            if(nums[left] <= nums[mid]){  //左边升序
                if(target >= nums[left] && target <= nums[mid]){//在左边范围内
                    right = mid-1;
                }else{//只能从右边找
                    left = mid+1;
                }
            }else{ //右边升序
                if(target >= nums[mid] && target <= nums[right]){//在右边范围内
                    left = mid +1;
                }else{//只能从左边找
                    right = mid-1;
                }
            }
            mid = left + (right-left)/2;
        }
        return -1;  //没找到
    }
```
## No.355设计推特

1.题目
```
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：

1.postTweet(userId, tweetId): 创建一条新的推文
2.getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
3.follow(followerId, followeeId): 关注一个用户
4.unfollow(followerId, followeeId): 取消关注一个用户
```
2.分析
+ 首先创建一些数据结构，存储用户ID、关注的人的ID、发表的推特；以及推特发表的时间：
```
struct Node {
        // 哈希表存储关注人的 Id
        unordered_set<int> followee;
        // 用链表存储 tweetId
        list<int> tweet;
    };
    // getNewsFeed 检索的推文的上限以及 tweetId 的时间戳
    int recentMax, time;
    // tweetId 对应发送的时间
    unordered_map<int, int> tweetTime;
    // 每个用户存储的信息
    unordered_map<int, Node> user;
```
+ 注意，由于题目中没有说明用户的 Id 是否连续，所以我们需要用一个以用户 Id 为索引的**哈希表**来存储用户的信息
+ 对于操作 3 和操作 4，我们只需要用一个哈希表存储，即可实现插入和删除的时间复杂度都为 O(1)。
+ 对于操作 1 和操作 2，可以考虑对每个用户用链表存储发送的推文。每次创建推文的时候我们在链表头插入，这样能保证链表里存储的推文的时间是从最近到最久的。那么对于操作 2，问题其实就等价于有若干个有序的链表，我们需要找到它们合起来最近的十条推文。（参考**题目No.25**）

3.哈希表
+ unordered_set<T> 容器类型的模板定义在 unordered_set 头文件中。unordered_set<T> 容器提供了和 unordered_map<T> 相似的能力，但 unordered_set<T> 可以用保存的元素作为它们自己的键。T 类型的对象在容器中的位置由它们的哈希值决定，因而需要定义一个 Hash<T> 函数。
+ 这种容器不能存放重复的元素。元素类型必须可以比较是否相等，因为这可以确定元素什么时候相等。就像 uordered_map，元素被存放在哈希表内部的格子中。每个格子保存哪个元素，是由元素的哈希值决定的。

4.**emplace()和insert()的区别**

  可以看到，通过 insert() 函数向 vector 容器中插入类对象时，需要调用类的构造函数和移动构造函数（或拷贝构造函数）；而通过 emplace() 函数实现同样的功能，只需要调用构造函数即可。

 简单的理解，就是 emplace() 在插入元素时，是在容器的指定位置原地直接构造元素，而不是先单独生成，再将其复制（或移动）到容器中。
 
 **实际使用中，推荐优先使用 emplace()**

5.iterator

[这里的总结很详细，一定要看！](http://c.biancheng.net/view/338.html)
```
容器	迭代器功能
vector	随机访问
deque	随机访问
list	双向
set / multiset	双向
map / multimap	双向
stack	不支持迭代器
queue	不支持迭代器
priority_queue	不支持迭代器
```

6.实现

选择有代表性的两个函数：
```
 void postTweet(int userId, int tweetId) {
        if (user.find(userId) == user.end()) {
            init(userId);
        }
        // 达到限制，剔除链表末尾元素
        if (user[userId].tweet.size() == recentMax) {
            user[userId].tweet.pop_back();//user是unordered_map
        }
        user[userId].tweet.push_front(tweetId);
        tweetTime[tweetId] = ++time;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans; ans.clear();
        for (list<int>::iterator it = user[userId].tweet.begin(); it != user[userId].tweet.end(); ++it) {
            ans.emplace_back(*it);
        }
        for (int followeeId: user[userId].followee) {
            if (followeeId == userId) continue; // 可能出现自己关注自己的情况
            vector<int> res; res.clear();
            list<int>::iterator it = user[followeeId].tweet.begin();
            int i = 0;
            // 线性归并
            while (i < (int)ans.size() && it != user[followeeId].tweet.end()) {
                if (tweetTime[(*it)] > tweetTime[ans[i]]) {
                    res.emplace_back(*it);
                    ++it;
                } else {
                    res.emplace_back(ans[i]);
                    ++i;
                }
                // 已经找到这两个链表合起来后最近的 recentMax 条推文
                if ((int)res.size() == recentMax) break;
            }
            for (; i < (int)ans.size() && (int)res.size() < recentMax; ++i) res.emplace_back(ans[i]);
            for (; it != user[followeeId].tweet.end() && (int)res.size() < recentMax; ++it) res.emplace_back(*it);
            ans.assign(res.begin(),res.end());
        }
        return ans;
    }
```
## No.23 合并k个排序链表

1.题目
```
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:
输入:
[ 1->4->5,
  1->3->4,
  2->6 ]
输出: 1->1->2->3->4->4->5->6
```
2.**优先队列priority_queue**
+ priority_queue 容器适配器定义了一个元素有序排列的队列。每次弹出优先级最高的元素。
  - priority_queue 模板有 3 个参数，其中两个有默认的参数；第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象，它定义了一个用来决定元素顺序的断言。
  - 模板是：
  ```
  template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue
  ```
+ priority_queue优先队列的实质还是堆排序，默认的优先队列是以大顶堆构造，即序列中最大数的优先级最高，通过top()可以访问当前优先级最高的数，pop()来弹出当前优先级最高的数。
  - priority_queue的比较函数的意义与sort函数的比较函数相类似，均是当比较函数返回true时，将第一个参数放在第二个参数前面。默认比较函数为less<T>,和小于操作符的作用一样，即让较小的数放在前面。
  - 当你调用pop()时，实际上是弹出优先队列的序列中的最后一个数(back)，而这个被弹出的数也就是priority_queue的top()。也就是说，我们所认为的top()和pop()是获取、弹出优先级最高的数，实际上这个数就是当前优先队列序列中的最后一个数。
  - 这似乎也就不难解释cmp比较函数与优先队列返回的最大值之间的关系了：以默认的比较函数less<T>为例，它的作用是将较小的数放在前面，因此最大的数肯定就位于序列的末尾了，当调用top()函数时，返回末尾的数，也就是序列中最大的数，而pop()则弹出这个数，而这个数，通常被认为是“优先级最高”的数。
+ **自定义priority_queue的比较函数**
  - 重载小于操作符
  ```
  //从小到大排列，先弹出末尾的大数，构建的是较大数优先的大根堆
  bool operator<(const stu &p)const
    {
        return age<p.age;
    }
  ```
  - 自定义仿函数
  ```
  //从大到小排列，先弹出末尾的小数，构建的是较小数优先的小根堆
  struct cmp
   {
    operator ()(const stu &q,const stu &p)
    {
        return q.num>p.num;
    }

  ```
[具体可以参考这篇文章](https://blog.csdn.net/qq_28114615/article/details/86495567)

3.哨兵节点

+ **哨兵节点**：哨兵节点（sentinel）是一个哑元节点（dummy node），可以简化边界条件。是一个附加的链表节点，该节点作为第一个节点，它的值域中并不存储任何东西，只是为了操作的方便而引入的。如果一个链表有哨兵节点的话，那么线性表的第一个元素应该是链表的第二个节点。

  - 很多情况下，需要处理当前节点的前驱节点，如果是没有哨兵节点的链表，对第一个节点，即头节点，没有前驱节点。如果不作特殊处理，就可能出错；如果对它特别对待，就会增加代码复杂性，还会降低程序效率。而如果有哨兵节点的话， 线性表的每个位置的节点都有前驱节点，因此可以统一处理。

  - 当链表为空时，没有哨兵节点的链表的头节点为NULL，处理起来也和其他情况不同。带哨兵节点的链表，当其为一个空链表时，仅含哨兵节点，哨兵节点的指针域为空，和其他情况的表尾是一样的。
+ 哨兵节点的实现：
```
ListNode dummy(-1);
ListNode* p = &dummy;
// 开始出队
while(!pri_queue.empty()){
     ListNode* top = pri_queue.top(); pri_queue.pop();
     p->next = top; p = top;
     if(top->next) pri_queue.push(top->next);
   }
   return dummy.next;  
```

4.优先队列的方法

建立优先队列，不需要全部元素一次性入队；只需要让链表头元素入队即可，弹出该元素后，该链表往后移。
```
 // 小根堆的回调函数
    struct cmp{  
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pri_queue;
        // 建立大小为k的小根堆
        for(auto elem : lists){
            if(elem) pri_queue.push(elem);
        }
        // 可以使用哑节点/哨兵节点
        ListNode dummy(-1);
        ListNode* p = &dummy;
        // 开始出队
        while(!pri_queue.empty()){
            ListNode* top = pri_queue.top(); pri_queue.pop();
            p->next = top; p = top;
            if(top->next) pri_queue.push(top->next);
        }
        return dummy.next;  
    }
```
5.两两合并的方法
```
 // 合并两个有序链表
    ListNode* merge(ListNode* p1, ListNode* p2){
        if(!p1) return p2;
        if(!p2) return p1;
        if(p1->val <= p2->val){
            p1->next = merge(p1->next, p2);
            return p1;
        }else{
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }

     ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head = lists[0];
        for(int i = 1; i<lists.size(); ++i){
            if(lists[i]) head = merge(head, lists[i]);
        }
        return head;  
    }
```
## No.445 两数相加 II

1.题目
```
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7
```
2.**初始化一个链表的正确打开方式**

+ 利用头部哨兵节点创建
```
 ListNode* res = new ListNode(0);//可以认为是头部哨兵节点
 ListNode* result=res;
 ......
 for(int j = count-1;j>=0;j--){
            ListNode* cur = new ListNode;
            cur->val = j;
            cur->next = NULL;
            result->next = cur;
            result = result->next;
        }
 return res->next;
```
+ 还有一种**尾部哨兵节点**的例子，从后往前构建链表！

**注意**尾节点可以这么定义，还不占用内存 ListNode* ans = nullptr;
```
ListNode* ans = nullptr;
......
ListNode* curnode = new ListNode(cur);
          curnode -> next = ans;
          ans = curnode;
        }
        return ans;
```
+ 一种简单的遍历链表所有元素的写法**while(l1)**
```
ListNode* l1;
stack<int> s1;
while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
```
3.实现

本题的主要难点在于链表中数位的顺序与我们做加法的顺序是相反的，为了逆序处理所有数位，我们可以使用栈：把所有数字压入栈中，再依次取出相加。计算过程中需要注意进位的情况。

```
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {//排除进位和数字长度不一干扰的关键性判断！
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
    }
```
## No.542 01矩阵(BFS+动态规划)

1.题目
```
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。两个相邻元素间的距离为 1 。
输入:
0 0 0
0 1 0
1 1 1
输出:
0 0 0
0 1 0
1 2 1
```
2.constexpr修饰符

+ constexpr是C++11中新增的关键字，其语义是“常量表达式”，也就是在编译期可求值的表达式。最基础的常量表达式就是字面值或全局变量/函数的地址或sizeof等关键字返回的结果，而其它常量表达式都是由基础表达式通过各种确定的运算得到的。constexpr值可用于enum、switch、数组长度等场合。

+ constexpr还能用于修饰类的构造函数，即保证如果提供给该构造函数的参数都是constexpr，那么产生的对象中的所有成员都会是constexpr，该对象也就是constexpr对象了，可用于各种只能使用constexpr的场合。注意，constexpr构造函数必须有一个空的函数体，即所有成员变量的初始化都放到初始化列表中。

+constexpr的好处：
  - 是一种很强的约束，更好地保证程序的正确语义不被破坏。
  - 编译器可以在编译期对constexpr的代码进行非常大的优化，比如将用到的constexpr表达式都直接替换成最终结果等。
  - 相比宏来说，没有额外的开销，但更安全可靠
  
3.BFS方法
+ 我们可以从 00 的位置开始进行 广度优先搜索。广度优先搜索可以找到从起点到其余所有点的 最短距离，因此如果我们从 00 开始搜索，每次搜索到一个 11，就可以得到 00 到这个 11 的最短距离，也就离这个 11 最近的 00 的距离了（因为矩阵中只有一个 00）。

+ 思路：
  - 对于 「Tree 的 BFS」 （典型的「单源 BFS」） 大家都已经轻车熟路了：
    - 首先把 root 节点入队，再一层一层无脑遍历就行了。
  - 对于 「图 的 BFS」 （「多源 BFS」） 做法其实也是一样滴～，与 「Tree 的 BFS」的区别注意以下两条就 ok 辣～
    - Tree 只有 1 个 root，而图可以有多个源点，所以首先需要把多个源点都入队；
    - Tree 是有向的因此不需要标识是否访问过，而对于无向图来说，必须得标志是否访问过哦！并且为了防止某个节点多次入队，需要在其入队之前就将其设置成已访问！【 看见很多人说自己的 BFS 超时了，坑就在这里哈哈哈

+ 举例来看
```
假设矩阵中有两个0，剩余的1我们用短横线表示:
_ _ _ _ 
_ 0 _ _   ==> 
_ _ 0 _
_ _ _ _

_ 1 _ _         2 1 2 _         2 1 2 3
1 0 1 _   ==>   1 0 1 2   ==>   1 0 1 2
_ 1 0 1         2 1 0 1         2 1 0 1
_ _ 1 _         _ 2 1 2         3 2 1 2
```
+ 实现：
```
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }
        // 广度优先搜索
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }
    return dist;
    }
};
```
4.动态规划方法
+ 尝试将问题分解：
  - 距离 (i,j) 最近的 0 的位置，是在其 「左上，右上，左下，右下」4个方向之一；
  - 因此我们分别从四个角开始递推，就分别得到了位于「左上方、右上方、左下方、右下方」距离 (i,j) 的最近的 0 的距离，取min 即可；
  - 通过上两步思路，我们可以很容易的写出 4 个双重for 循环，动态规划的解法写到这一步其实已经完全 OK 了；
+ 如果第三步还不满足的话，从四个角开始的 4 次递推，其实还可以优化成从任一组对角开始的 2 次递推，比如只写从左上角、右下角开始递推就行了
  - 首先从左上角开始递推 dp[i][j] 是由其 「左方」和 「左上方」的最优子状态决定的；
  - 然后从右下角开始递推 dp[i][j] 是由其 「右方」和 「右下方」的最优子状态决定的；
  - 看起来第一次递推的时候，把「右上方」的最优子状态给漏掉了，其实不是的，因为第二次递推的时候「右方」的状态在第一次递推时已经包含了「右上方」的最优子状态了；
  - 看起来第二次递推的时候，把「左下方」的最优子状态给漏掉了，其实不是的，因为第二次递推的时候「右下方」的状态在第一次递推时已经包含了「左下方」的最优子状态了。
+ 也可以这样理解，从最近的0走到1，肯定只能从1周围上下左右4个点走到1，第一次从左上角到右下角遍历整个表，到表中任意位置i的时候，i上方和左方的位置已经遍历过了，所以可以判断从上方进入这个1和左方进入这个1的状况哪个最近，并在dp数组保存。同理，第二次从右下角到左上角遍历整个表到i位置时，i右方和下方的位置状态已经更新过了，所以能判断从右边进入合算还是从下边进入合算，再加上第一次遍历保存的左方和上方的最优解就能判断出上下左右四个方向的最优解了

+ 四次动态规划的实现(**一定要注意动态规划的计算顺序**)
```
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 初始化动态规划的数组，所有的距离值都设置为一个很大的数
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));
        // 如果 (i, j) 的元素为 0，那么距离为 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                }
            }
        }
        // 只有 水平向左移动 和 竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        // 只有 水平向左移动 和 竖直向下移动，注意动态规划的计算顺序
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m) {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        // 只有 水平向右移动 和 竖直向上移动，注意动态规划的计算顺序
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        // 只有 水平向右移动 和 竖直向下移动，注意动态规划的计算顺序
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i + 1 < m) {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        return dist;
    }
};
```
## No.56 合并区间

1.题目
```
给出一个区间的集合，请合并所有重叠的区间。区间集合的顺序是不规则的。
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```
2.**空 vector和vector初始化的一些知识**
+ 空vector的判断和返回:

```
vector<vector<int>> intervals;
if (intervals.size() == 0) {
            return {};
        }
```
+ vector初始化的一些问题
  - **如果声明vector时没有进行初始化，那么后面的赋值操作只可以有push_back，而不可以用"="赋值**
  
  并且赋值时，vector变量后面不可以加下标!
  ```
  vector<vector<int>> res;
  res.push_back(intervals[i]);//这样是可以的！
  res[i].push_back(intervals[i]);//这样是错误的！因为没初始化，不可以在res后添加下标 
  ```
 - 如果声明时vector进行了初始化，**那么push_back操作将会在原初始化大小的后面添加元素；想改变初始化大小内的元素需要用"="!**
 ```
 vector<vector<int>> res(rows,vector<int>(cols));//rows X cols的二维vector，里面元素没赋值时，初始化为0
 res[0].push_back(5);//是对的，但是赋值位置在res[0][cols]
 res[0][0]=5;//是对的
 ```
+ vector中也有front()和back()，分别表示vector中的第一个和最后一个元素。

3.分析
+ 排序后比较右端点数大小。我们用数组 merged 存储最终的答案。
  - 首先，我们将列表中的区间**按照左端点升序排序**。然后我们将第一个区间加入 merged 数组中，并按顺序依次考虑之后的每个区间：
  - 如果**当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合**，我们可以直接将这个区间加入数组 merged 的末尾；
  - 否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。
+ 实现：
```
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
## No.1162 地图分析

1.题目
```
你现在手里有一份大小为 N x N 的「地图」（网格） grid，上面的每个「区域」（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋区域，这个海洋区域到离它最近的陆地区域的距离是最大的。
我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
如果我们的地图上只有陆地或者海洋，请返回 -1。
```
2.需要总结**三种最短路径算法**
+ Dijkstra算法
+ Floyd算法
+ SPFA算法

3.研究**多源的BFS！**

4.经典做法（BFS）
+ 考虑最朴素的方法，即求出每一个海洋区域（grid[i][j] == 0 的区域）的「最近陆地区域」，然后记录下它们的距离，然后在这些距离里面取一个最大值。
+ 对于一个给定的区域 (x,y) ，求它的「最近陆地区域」，可以使用宽度优先搜索思想。我们把每个区域的坐标作以及这个区域与(x,y) 的曼哈顿距离为搜索状态，即 Coordinate 结构体的 x、y 和 step 属性。findNearestLand 方法实现了宽度优先搜索的过程，用一个 vis[u][v] 数组记录(u,v) 区域是否被访问过.
+ 具体实现
```
class Solution {
public:
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    static constexpr int MAX_N = 100 + 5;

    struct Coordinate {
        int x, y, step;
    };

    int n, m;
    vector<vector<int>> a;
    bool vis[MAX_N][MAX_N];
    int findNearestLand(int x, int y) {
        memset(vis, 0, sizeof vis);
        queue <Coordinate> q;
        q.push({x, y, 0});
        vis[x][y] = 1;
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)) continue;
                if (!vis[nx][ny]) {
                    q.push({nx, ny, f.step + 1});
                    vis[nx][ny] = 1;
                    if (a[nx][ny]) return f.step + 1;
                }
            }
        }
        return -1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid.at(0).size();
        a = grid;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                    ans = max(ans, findNearestLand(i, j));
                }
            }
        }
        return ans;
    }
};
```
5.多源BFS方法

实现
```
class Solution {
public:
    static constexpr int MAX_N = 100 + 5;
    static constexpr int INF = int(1E6);
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int n;
    int d[MAX_N][MAX_N];

    struct Coordinate {
        int x, y;
    };
    queue <Coordinate> q;
    int maxDistance(vector<vector<int>>& grid) {
        this->n = grid.size();
        auto &a = grid;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = INF;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j]) {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1)) continue;
                if (d[nx][ny] > d[f.x][f.y] + 1) {
                    d[nx][ny] = d[f.x][f.y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!a[i][j]) ans = max(ans, d[i][j]);
            }
        }

        return (ans == INF) ? -1 : ans;
    }
};
```
## No.55 跳跃游戏

1.题目
```
给定一个非负整数数组，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。
输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
```
2.分析
+ 可以使用贪心算法
  - 依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置。对于当前遍历到的位置 xx，如果它在**最远可以到达**的位置的范围内，那么我们就可以从起点通过若干次跳跃到达该位置，因此我们可以用**x+nums[x] 更新最远可以到达**的位置。
  - 在遍历的过程中，如果**最远可以到达的位置大于等于数组中的最后一个位置**，那就说明最后一个位置可达，我们就可以直接返回 True 作为答案。反之，如果在遍历结束后，最后一个位置仍然不可达，我们就返回 False 作为答案。
+ 实现
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
```
3.**还有一种更极致的判断方法！**
```
//(1)如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
//(2)可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
//(3)如果可以一直跳到最后，就成功了。
bool canJump(vector<int>& nums) 
{
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) return false;
		k = max(k, i + nums[i]);
	}
	return true;
}
```
## No.53 最大子序和

1.题目
```
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```
2.使用动态规划的思想是自然而然的。

**dp[i]表示nums中以nums[i]结尾的最大子序和**
```
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(numsSize);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < numsSize; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};
```
3.迷之分治算法

+ 这个是使用分治法解决问题的典型的例子，并且可以用与合并排序相似的算法求解。下面是用分治法解决问题的模板：
  - 定义基本情况。
  - 将问题分解为子问题并递归地解决它们。
  - 合并子问题的解以获得原始问题的解。
+ 算法：
  - 当最大子数组有 n 个数字时：
  - 若 n==1，返回此元素。
  - left_sum 为最大子数组前 n/2 个元素，在索引为 (left + right) / 2 的元素属于左子数组。
  - right_sum 为最大子数组的右子数组，为最后 n/2 的元素。
  - cross_sum 是包含左右子数组且含索引 (left + right) / 2 的最大值。
+ 实现：
```
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        result = maxSubArrayHelper(nums, 0, numsSize - 1);
        return result;
    }
    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right) / 2;
        int leftSum = maxSubArrayHelper(nums, left, mid);
        //注意这里应是mid + 1，否则left + 1 = right时，会无限循环
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);
        int result = max(leftSum, rightSum);
        result = max(result, midSum);
        return result;
    }
    int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
    }
};
```
## No.466 统计重复个数(**使用hash表！**)
1.题目
```
由 n 个连接的字符串 s 组成字符串 S，记作 S = [s,n]。例如，["abc",3]=“abcabcabc”。
如果我们可以从 s2 中删除某些字符使其变为 s1，则称字符串 s1 可以从字符串 s2 获得。例如，根据定义，"abc" 可以从 “abdbec” 获得，但不能从 “acbbe” 获得。
现在给你两个非空字符串 s1 和 s2（每个最多 100 个字符长）和两个整数 0 ≤ n1 ≤ 106 和 1 ≤ n2 ≤ 106。现在考虑字符串 S1 和 S2，其中 S1=[s1,n1] 、S2=[s2,n2] 。
请你找出一个可以满足使[S2,M] 从 S1 获得的最大整数 M 。
输入：
s1 ="acb",n1 = 4
s2 ="ab",n2 = 2
返回：2
```
2.**map中find()和count()的区别——如何判断unordered_map 判断某个键是否存在**
+ unordered_map c++ reference 是c++ 哈希表的实现模板，在头文件<unordered_map>中，存储key-value的组合，unordered_map可以在常数时间内，根据key来取到value值。
+ find()函数
  - 返回的是被查找元素的位置，没有则返回map.end()。。
  - 因此可以通过map.find(key) == map.end()来判断，key是否存在于当前的unordered_map中。
+ count()函数
 - count函数用以统计key值在unordered_map中出现的次数。实际上，c++ unordered_map不允许有重复的key。因此，如果key存在，则count返回1，如果不存在，则count返回0.
+ map与unordered_map相比：
  - map底层实现为红黑数，undered_map底层实现为哈希表，两者均不能有重复的建，均支持[]运算符
+ map与multimap相比：
  - 两者底层实现均为红黑树，但是multimap支持重复的键，不支持[]运算符


3.分析

![image](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/images/466_fig1.png)

+ 由于题目中的 n1 和 n2 都很大，因此我们无法真正把 S1 = [s1, n1] 和 S2 = [s2, n2] 都显式地表示出来。由于这两个字符串都是不断循环的，因此我们可以考虑找出 s2 在 S1 中出现的循环节，如果我们找到了循环节，那么我们就可以很快算出 s2 在 S1 中出现了多少次了。
+ 当我们找出循环节后，我们即可知道一个循环节内包含 s1 的数量，以及在循环节出现前的 s1 的数量，这样就可以在 O(1) 的时间内，通过简单的运算求出 s2 在 S1 中出现的次数了。当然，由于 S1 中 s1 的数量 n1 是有限的，因此可能会存在循环节最后一个部分没有完全匹配，如上图最后会单独剩一个 s1 出来无法完全匹配完循环节，这部分我们需要单独拿出来遍历处理统计。
+ 实现
```
int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) {
            return 0;
        }
        int s1cnt = 0, index = 0, s2cnt = 0;
        // recall 是我们用来找循环节的变量，它是一个哈希映射
        // 我们如何找循环节？假设我们遍历了 s1cnt 个 s1，此时匹配到了第 s2cnt 个 s2 中的第 index 个字符
        // 如果我们之前遍历了 s1cnt' 个 s1 时，匹配到的是第 s2cnt' 个 s2 中同样的第 index 个字符，那么就有循环节了
        // 我们用 (s1cnt', s2cnt', index) 和 (s1cnt, s2cnt, index) 表示两次包含相同 index 的匹配结果
        // 那么哈希映射中的键就是 index，值就是 (s1cnt', s2cnt') 这个二元组
        // 循环节就是；
        //    - 前 s1cnt' 个 s1 包含了 s2cnt' 个 s2
        //    - 以后的每 (s1cnt - s1cnt') 个 s1 包含了 (s2cnt - s2cnt') 个 s2
        // 那么还会剩下 (n1 - s1cnt') % (s1cnt - s1cnt') 个 s1, 我们对这些与 s2 进行暴力匹配
        // 注意 s2 要从第 index 个字符开始匹配
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        while (true) {
            // 我们多遍历一个 s1，看看能不能找到循环节
            ++s1cnt;
            for (char ch: s1) {
                if (ch == s2[index]) {
                    index += 1;
                    if (index == s2.size()) {
                        ++s2cnt;
                        index = 0;
                    }
                }
            }
            // 还没有找到循环节，所有的 s1 就用完了
            if (s1cnt == n1) {
                return s2cnt / n2;
            }
            // 出现了之前的 index，表示找到了循环节
            if (recall.count(index)) {
                auto [s1cnt_prime, s2cnt_prime] = recall[index];
                // 前 s1cnt' 个 s1 包含了 s2cnt' 个 s2
                pre_loop = {s1cnt_prime, s2cnt_prime};
                // 以后的每 (s1cnt - s1cnt') 个 s1 包含了 (s2cnt - s2cnt') 个 s2
                in_loop = {s1cnt - s1cnt_prime, s2cnt - s2cnt_prime};
                break;
            }
            else {
                recall[index] = {s1cnt, s2cnt};
            }
        }
        // ans 存储的是 S1 包含的 s2 的数量，考虑的之前的 pre_loop 和 in_loop
        int ans = pre_loop.second + (n1 - pre_loop.first) / in_loop.first * in_loop.second;
        // S1 的末尾还剩下一些 s1，我们暴力进行匹配
        int rest = (n1 - pre_loop.first) % in_loop.first;
        for (int i = 0; i < rest; ++i) {
            for (char ch: s1) {
                if (ch == s2[index]) {
                    ++index;
                    if (index == s2.size()) {
                        ++ans;
                        index = 0;
                    }
                }
            }
        }
        // S1 包含 ans 个 s2，那么就包含 ans / n2 个 S2
        return ans / n2;
    }
```
## No.435 无重叠区
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
```
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
```
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
## No.200 岛屿数量

1.题目
```
你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
输入:
11110
11010
11000
00000
输出: 1
输入:
11000
11000
00100
00011
输出: 3
```
2.一些技巧
+ **队列中嵌套pair的声明和赋值**：
```
queue<pair<int,int>> res;
res.push(make_pair(i,j));
```
+ **在二维vector里面判断空集时，一定要在调用vector下标前判断！！**
 - 以下错误！
 ```
 int rows = grid.size();
 int cols = grid[0].size();//这段代码因为为空，所以直接出错！
 if(rows == 0){
     return 0;
        }
 ```
 - 以下正确！
 ```
  int rows = grid.size();
  if(rows == 0){
      return 0;
        }
  int cols = grid[0].size();
 ```
3.分析
+ BFS算法
 -为了求出岛屿的数量，我们可以扫描整个二维网格。如果一个位置为 1，则将其加入队列，开始进行广度优先搜索。在广度优先搜索的过程中，每个搜索到的 1 都会被重新标记为 0。直到队列为空，搜索结束。
最终岛屿的数量就是我们进行广度优先搜索的次数。
 - 实现
 ```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0){
            return 0;
        }
        int cols = grid[0].size();
        queue<pair<int,int>> res;
        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    count++;
                    //queue<pair<int,int>> res;
                    res.push(make_pair(i,j));
                    grid[i][j] = '0';
                    while(!res.empty()){
                        auto [r,c] = res.front();
                        res.pop();
                        if(r-1>=0&&grid[r-1][c]=='1'){
                            res.push(make_pair(r-1,c));
                            grid[r-1][c]='0';
                        }
                        if(r+1<rows&&grid[r+1][c]=='1'){
                            res.push(make_pair(r+1,c));
                            grid[r+1][c]='0';
                        }
                        if(c-1>=0&&grid[r][c-1]=='1'){
                            res.push(make_pair(r,c-1));
                            grid[r][c-1]='0';
                        }
                        if(c+1<cols&&grid[r][c+1]=='1'){
                            res.push(make_pair(r,c+1));
                            grid[r][c+1]='0';
                        }
                    }   
                }
            }
        }
        return count;
    }
};
 ```

## No.324 摆动排序

1.题目
```
给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
输入: nums = [1, 3, 2, 2, 3, 1]
输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
```
2.**要总结一下快速排序、快速选择、3-way-partition算法**
