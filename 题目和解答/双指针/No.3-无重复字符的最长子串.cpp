class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0) return 0;
        unordered_set<char> uset;//存储不包含重复字符的子串
        int res = 0;
        int left = 0;//滑窗中的左指针
        for(int i=0;i<len;++i){//i相当于右指针
            while(uset.find(s[i]) != uset.end() ){
                uset.erase(s[left]);
                left++;
            }
            uset.insert(s[i]);
            res = max(res,i-left+1);
        }
        return res;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = (int)s.size();
        if(size==0){
            return 0;
        } 
        int lastLen = 1;
        int max = 1;
        int curLen = 0;
        for(int i=1; i<size; ++i){
            curLen = 0;
            for(int j=i-lastLen; j<=i-1; ++j){
                if(s[j]==s[i]){
                    curLen = i-j;
                    break;
                }
            }
            if(curLen==0){
                curLen = lastLen + 1;
            }
            
            if(curLen>max){
                max = curLen;
            }

            lastLen = curLen;
        }
        return max;
    }
};
