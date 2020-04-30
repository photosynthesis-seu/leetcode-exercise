class Solution {
public:
    int SquareSum(int n){
        int res= 0;
        while(n){
            int num = n%10;
            n = n/10;
            res += num*num;
        }
        return res;
    }
    bool isHappy(int n) {
        int SlowRunner = n;
        int FastRunner = SquareSum(n);
        while(FastRunner != 1 && FastRunner != SlowRunner){
        SlowRunner = SquareSum(SlowRunner);
        FastRunner = SquareSum(SquareSum(FastRunner));
        }
        return FastRunner == 1; 
    }
    // bool isHappy(int n) {
    //     unordered_set<int> res;
    //     while(n != 1 && res.find(n) == res.end()){
    //     res.insert(n);
    //     n = SquareSum(n);
    //     }
    //     if(n==1){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
        
    // }
};
