class Solution {
public:
    vector<vector<int>> edges;//存储有向图
    vector<int> indeg;//存储每个节点的入度
    vector<int> result;//存储最终课程排序结果
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //使用队列保存入度为0的节点(入度为0，即为此课程需要先修的课程都修完了)
        queue<int> bfs;
        edges.resize(numCourses);
        indeg.resize(numCourses);
        //初始化有向图，方向为先修课程指向依赖此先修课程的其他课程。
        for(auto info : prerequisites){
            edges[info[1]].push_back(info[0]);
            indeg[info[0]] ++;
        }
        for(int i=0;i<indeg.size();i++){//将一开始就入度为0的点加入队列
            if(indeg[i] == 0){
                bfs.push(i);
            }
        }
        while(!bfs.empty()){//开始广度优先搜索
            auto course = bfs.front();
            bfs.pop();
            result.push_back(course);//先将队列头添加入答案
            for(auto depend_course : edges[course]){//将依赖于对队列头课程的课程，入度-1.
                indeg[depend_course]--;
                if(indeg[depend_course] == 0){//如果这些课程入度为0，入队列
                    bfs.push(depend_course);
                }
            }
        }
        if(result.size() == numCourses){
            return result;
        }
        else{
            return {};
        }
    }
};
