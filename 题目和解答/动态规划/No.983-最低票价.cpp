class Solution {
public:
    unordered_set<int> travaldays;//保存旅行日期
    vector<int> memo;//类成员不能直接初始化，要在成员函数里初始化！
    vector<int> costs;//全局声明，这样dp函数就可以直接用了，不用传参costs[]。
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo.resize(366,-1);//记录从任意一天开始旅行的最小花费
        this->costs = costs;
        for(auto tarvelday : days){
            travaldays.insert(tarvelday);
        }
        int result = dp(1);
        return result;
    }
    int dp(int startday){
        if(startday > 365){
            return 0;
        }
        if(memo[startday] != -1){
            return memo[startday];
        }
        if(!travaldays.count(startday)){
            //注意这里是dp(startday+1)不是memo[startday+1],因为是从后往前动态规划，要先把后面动态规划的值求出来
            memo[startday] = dp(startday+1);
        }
        else{
            memo[startday] = min(dp(startday+1)+costs[0],min(dp(startday+7)+costs[1],dp(startday+30)+costs[2]));
        }
        return memo[startday];
        
    }
};
