//待回溯的递归算法
class Solution {
public:
    vector<string> res;
    string cur;
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
    vector<string> generateParenthesis(int n) {
        if(n==0){
            res.push_back("");
            return res;
        }
        useful(res,cur,0,0,n);
        return res;
    }
};
