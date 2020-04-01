//方法1：
class Solution {
public:
    string longestPalindrome(string s) {
        //字符串最好进行初始化
        string sub_s = "";//子串
        string reverse_sub_s = "";//反转后的子串
        string result = "";//最长回文子串
        //相当于用两个循环中的i、j实现了指针一样的功能，对字符串遍历
        for(int i = 0;i < s.length();i++){
            for(int j = i;j < s.length();j++){
                sub_s += s[j];
                reverse_sub_s = sub_s;
                reverse(reverse_sub_s.begin(),reverse_sub_s.end());
                if(sub_s == reverse_sub_s&&sub_s.length() >= result.length()){
                    result = sub_s;
                } 
                // else{
                //     break;
                // }这段话不能加，因为会干扰下一次循环找最长字符串（下一次循环的字符串长度必然从1开始）
            } 
            sub_s = "";//内存循环结束后，注意要将子字符串清空
        }
        return result;
    }
};

//动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        if(length == 0 || length == 1){
            return s;
        }
        string reverse_s = s;
        std::reverse(reverse_s.begin(),reverse_s.end());
        if(reverse_s == s){
            return s;
        }
        vector<vector<int>> dp(length,vector<int>(length));//注意如何初始化二维vector
        int start = 0;
        int sub_length = 1;//回文字符串开始字符与长度，这两个变量是为了之后能输出回文串
        for(int i = 0;i<length;i++){
            dp[i][i] = 1;
            //添加相邻两个字符相等的回文字符，并动态更新为1；不要忘记i<length-1的条件
            if(i<length-1 && s[i] == s[i+1]){
                dp[i][i+1] = 1;
                sub_length = 2;
                start = i;//防止最长回文串就只有两个字符，定义好输出位置
            }
        }
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
        return s.substr(start,sub_length);
    }
};
