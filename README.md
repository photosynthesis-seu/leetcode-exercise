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
![image](https://github.com/photosynthesis-seu/leetcode-exercise/blob/master/images/50768703-58887400-12bc-11e9-881b-92ceb12c9cfe.png)
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
