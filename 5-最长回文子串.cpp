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
