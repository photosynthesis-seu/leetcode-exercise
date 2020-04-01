class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth_count=1;
        vector<int> result(seq.size());//还是需要进行初始化的
        if(seq == ""){
            result[0]=0;
            return result;
        }
        for(int i=0; i<seq.size(); i++){
            if(seq[i] == '('){
                ++depth_count;
                result[i]=depth_count%2;
            }
            else{
                result[i]=depth_count%2;
                --depth_count;
            }
        }
        return result;
    }
};
