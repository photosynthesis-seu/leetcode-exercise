class Solution {
public:
    // 会超时
    // bool validPalindrome(string s) {
    //     if(s.size() == 1 || s.size() == 2) return true;
    //     for(int i=0;i<s.size();i++){
    //         string temp1 = s;
    //         temp1.erase(i,1);
    //         string temp2 = temp1;
    //         reverse(temp1.begin(),temp1.end());
    //         if(temp1 == temp2){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    bool decision(string& s, int left, int right){
        for(;left<right;left++,right--){
            if(s[left] != s[right]){
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(s.size() == 1 || s.size() == 2) return true;
        int left = 0;
        int right = s.size()-1;
        for(;left<right;left++,right--){
            if(s[left] == s[right]){
                continue;
            }
            else{
                return decision(s,left+1,right)||decision(s,left,right-1);
            }
        }
        return true;
    }
};
