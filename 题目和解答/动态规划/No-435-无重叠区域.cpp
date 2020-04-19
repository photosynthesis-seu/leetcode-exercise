class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len==0) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int count = 1;
        int end = intervals[0][1];
        for(int i = 0;i<len;i++){
            if(intervals[i][0]>=end){
                count++;
                end = intervals[i][1];
            }
        }
        int res = len - count;
        return res;
    }
};
