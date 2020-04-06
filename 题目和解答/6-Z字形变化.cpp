自己的方法//
class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.size();
        int format = 2*numRows - 2;
        auto result1 = vector<string>(format,"");
        auto result2 = vector<string>(numRows);
        string final;
        if(numRows == 1 || numRows >= length){
            return s;
        }
        for(int i = 0; i<length; i++){
            result1[i%format] += s[i]; 
        }
        result2[0] = result1[0];
        result2[numRows-1] = result1[numRows-1];
        for(int i = 1; i<numRows-1; i++){
            if (result1[format - i] != ""){
                for(int j = 0;j<result1[i].size();j++){
                    result2[i] += result1[i][j];
                    if(result1[format - i][j] == NULL){
                        continue;
                    }
                    result2[i] += result1[format - i][j];
                }
            }
            else result2[i] = result1[i];
        }
        for(int i = 0; i<numRows; i++){
            final += result2[i];
        }
        return final;
};
//一种简练的算法
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
