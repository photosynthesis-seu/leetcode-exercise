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
