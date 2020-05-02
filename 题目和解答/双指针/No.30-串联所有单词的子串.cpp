class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size() == 0)//判断words为空,因为下面用到了words[0]
            return res;
        
        int word_size = words[0].size();
        int word_num = words.size();
        
        unordered_map<string,int> m1;//构造hashmap
        // for(int i=0;i<word_num;i++){
        //     m1[words[i]]++;
        // }
        //注意也可以用auto修饰符
        for(auto word : words){
            m1[word]++;
        }    
        unordered_map<string,int> m2;//统计滑窗中的单词
        for(int i=0; (i + word_size * word_num) <= s.size() ; i++){//截取的s符合题意
            int j = 0;
            for(j=i;j < (i + word_size * word_num) ; j=j+word_size){//分段判断
                string temp_str = s.substr(j,word_size);
                if(m1[temp_str] == 0){//m1中没有截取的串，直接跳出
                    break;
                }else{
                    m2[temp_str]++;
                    if(m1[temp_str] < m2[temp_str])//滑窗中单词出现次数超过了m1，也跳出
                        break;
                }
            }
            
            if(j == (i + word_size * word_num))//每一段都符合，则加入答案
                res.push_back(i);
            
            m2.clear();//清空m2,开始下一个滑窗
        }
        return res;
    }
};
