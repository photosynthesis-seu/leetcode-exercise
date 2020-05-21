class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        int res = 0;
        // -1表示空位
        vector<int> pos(80000, -1); 
        // 遍历每个数字a对其寻地址得到位置b, b比a的增量就是操作数。
        for (int a: A)
        {
            int b = findPos(a, pos);
            res += b-a;
        }
        return res;
    }
    // 线性探测寻址(状态压缩)
    int findPos(int a, vector<int> &pos)
    {
        int b = pos[a];
        // a对应的位置pos[a]是空位，直接放入
        if (b==-1)
        {
            pos[a] = a;
            return a;
        }
        // 向后寻址
        b = findPos(b+1, pos);
        pos[a] = b;
        return b;
    }
};
