class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0 ||height.size() == 1||height.size() == 2){
            return 0;
        }
        int result = 0;
        int size = height.size();
        vector<int>Left_Max(size);//动态规划，两个备忘录
        vector<int>Right_Max(size);//存放每个柱子左边和右边的最大高度
        Left_Max[0] = height[0];
        for(int i = 1; i < size-1;i++){
                Left_Max[i] = max(Left_Max[i-1],height[i]);
            }
        Right_Max[size-1] = height[size-1];
        for(int i = size - 2; i > 0; i--){
                Right_Max[i] = max(Right_Max[i+1],height[i]);
            }
        for(int i = 1;i < size-1;i++ ){
        result += min(Left_Max[i],Right_Max[i]) - height[i]; 
        }
         return result;
    }  
};
