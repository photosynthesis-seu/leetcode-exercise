
[参考链接](https://blog.nowcoder.net/n/6068ddfe58ad4a50ae0d0a89aef6af75)
# 第一题：
```C++
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


using namespace std;

bool is_special(int num){
    int temp = num/10;
    if(num%10 == 7 && temp%2 ==1){
        return true;
    }
    return false;
}

int main() {
    int M,N;
    cin>>M>>N;
    if(N<10 || N>1000 || M<10 || M>1000){
        cout<<"[]"<<endl;
        return 0;
    }
    int count = 0;
    vector<vector<int>> nums(M,vector<int>(N,0));
    vector<vector<int>> ans;
    int left = 0;
    int right = N-1;
    int top = 0;
    int bottom = M-1;
    while(1){
        for(int i=left;i<=right;i++){
            if(is_special(count)){
                ans.push_back({top,i});
            }
            count++;
        }
        if(++top > bottom) break;
        for(int i=top;i<=bottom;i++){
            if(is_special(count)){
                ans.push_back({i,right});
            }
            count++;
        }
        if(left > --right) break;
        for(int i=right;i>=left;i--){
            if(is_special(count)){
                ans.push_back({bottom,i});
            }
            count++;
        }
        if(top>--bottom) break;
        for(int i=bottom;i>=top;i--){
            if(is_special(count)){
                ans.push_back({i,left});
            }
            count++;
        }
        if(++left>right) break;
    }
    cout<<ans.size()<<endl;
    cout<<'[';
    for(int i=0;i<ans.size()-1;i++){
        cout<<'['<<ans[i][0]<<','<<ans[i][1]<<']'<<',';
    }
    cout<<'['<<ans[ans.size()-1][0]<<','<<ans[ans.size()-1][1]<<']'<<']';
    return 0;
}
```

## 第二题：
```C++
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_set>


using namespace std;

long long cal_num(long long a, long long b){
    long long ans = 1;
    for(long long i = a; i> a-b ; i--){
        ans *= i;
    }
    for(long long i = b; i>=1; i--){
        ans = ans/i;
    }
    return ans;
}

int main() {
    long long len;
    long long max_depth=0;
    long long ans = 1;
    long long index = pow(10,9)+7;
    cin>>len;
    vector<long long> nums;
    while(len){
        long long num;
        cin>>num;
        max_depth = max(max_depth,num);
        nums.push_back(num);
        len--;
    }
    map<long long,long long> memo;
    for(auto num:nums){
        memo[num]++;
    }
    if(!memo.count(0)){
        cout<<0<<endl;
        return 0;
    }
    for(long long i=1; i<=max_depth; i++){
        long long count = memo[i];
        if(count > pow(2,i)){
            cout<<0<<endl;
            return 0;
        }
        ans *= cal_num(2*memo[i-1],memo[i]);
        ans = ans % index;
    }
    cout<<ans<<endl;
    return 0;
}

```
