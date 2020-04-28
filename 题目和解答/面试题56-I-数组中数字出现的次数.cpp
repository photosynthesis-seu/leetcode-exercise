class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;//求全部数组异或的结果
        for(int n:nums){//由于交换律以及异或的性质，最终结果是两个只出现一次的数字的异或的结果。
            sum ^= n;
        }
        int make_part = 1;//寻找一位作为分组时的比较位，这一位应当在异或结果sum中是1，只有这样
        //才可以让两个只出现一次的数字分在不同组。
        while((make_part&sum) == 0){//根据运算符优先级，一定要加括号
            make_part = make_part<<1;
        }
        int a=0,b=0;
        for(int n:nums){//根据比较位，将数组分为两组
            if(make_part&n){//这里不可以写为make_part&n==1!
                a ^= n;
            }
            else{
                b ^= n;
            }
        }
        return (vector<int>{a,b});
    }
};
