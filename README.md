# leetcode-exercise
# C++题目总结
--No.1111 有效括号的嵌套深度
--学习到的一些知识：
1.vector<int>等容器在声明时，最好进行初始化 eg:vector<int> result(seq.size())；容器一般都有size()操作；
2.对于求字符串长度的函数：strlen/size/length的区别：
//方法一：调用length()或size()
string strTest="test";
strTest.length();			//结果为4
strTest.size();				//结果为4
//方法二：转为C风格字符串，调用strlen()
strlen(strTest.c_str());	//结果为4
3.嵌套深度的计算方法：可以通过栈实现括号匹配来计算。
维护一个栈 s，从左至右遍历括号字符串中的每一个字符：如果当前字符是 (，就把 ( 压入栈中，此时这个 ( 的嵌套深度为栈的高度；如果当前字符是 )，此时这个 ) 的嵌套深度为栈的高度，随后再从栈中弹出一个 (。
下面给出了括号序列 (()(())()) 在每一个字符处的嵌套深度：

括号序列   ( ( ) ( ( ) ) ( ) )
下标编号   0 1 2 3 4 5 6 7 8 9
嵌套深度   1 2 2 2 3 3 2 2 2 1 
知道如何计算嵌套深度，问题就很简单了：只要在遍历过程中，我们保证栈内一半的括号属于序列 A，一半的括号属于序列 B，那么就能保证拆分后最大的嵌套深度最小，是当前最大嵌套深度的一半。要实现这样的对半分配，我们只需要把奇数层的 ( 分配给 A，偶数层的 ( 分配给 B 即可。对于上面的例子，我们将嵌套深度为 1 和 3 的所有括号 (()) 分配给 A，嵌套深度为 2 的所有括号 ()()() 分配给 B。
