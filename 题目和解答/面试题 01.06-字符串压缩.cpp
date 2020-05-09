class Solution {
public:
    string compressString(string S) {
        string res;
        int len = S.size();
        if(len == 0||len == 1) return S;
        res.push_back(S[0]);
        int count = 1;
        string temp;
        for(int i=1;i<len;i++){
            if(S[i] == S[i-1]){
                count++;
            }
            else{
                // temp.clear();
                // while(count){
                //     temp.push_back(count%10+'0');
                //     count /= 10;
                // }
                // reverse(temp.begin(),temp.end());
                // for(auto ch : temp){
                //     res.push_back(ch);
                // }
                res += to_string(count);
                res.push_back(S[i]);
                count = 1;
            }
        }
        // temp.clear();
        // while(count){
        //     temp.push_back(count%10+'0');
        //      count /= 10;
        // }
        // reverse(temp.begin(),temp.end());
        // for(auto ch : temp){
        //      res.push_back(ch);
        // }
        res += to_string(count);
        if(res.size()>=len){
            return S;
        }
        else{
            return res;
        }
    }
};
