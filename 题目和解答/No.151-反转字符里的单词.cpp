//利用stack的暴力算法
class Solution {
public:
    string reverseWords(string s) {
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
         }
       
        while(!res.empty()){
            string temp = res.top()+" ";
            result += temp;
            res.pop();
        }
        result.pop_back();
        return result;
    }
};
