class Solution {
public:
    int myAtoi(string str) {
       int num=0;
    istringstream str_1(str);
    //while (num==0)
        str_1 >> num;
    if (num > INT_MAX)
        return INT_MAX;
    else if (num < INT_MIN)
        return INT_MIN;
    else
        return num;

    }
};
