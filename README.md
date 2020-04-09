# leetcode-exercise
# C++题目总结
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

## No42. 接雨水问题

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
            if(decision(cur)){
                res.push_back(cur);
            }
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
5.使用二叉树结构的DFS
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
    }
};
```
