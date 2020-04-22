//自己的方法(DFS)
**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {} ;
        }
        vector<int> count(1000,0);
        //int layer=0;
        //res.push_back(root->val);
        dfs(root,0,count);
        return res;
    }
    void dfs(TreeNode* root,int layer,vector<int>& count){
        if(count[layer] == 0){
             res.push_back(root->val);
             count[layer] = 1;
        }
        layer++;
        if (root->right != nullptr) dfs(root->right,layer,count);
        if (root->left != nullptr) dfs(root->left,layer,count);
    }
};
//BFS方法
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int, int> rightmostValueAtDepth;
        int max_depth = -1;

        queue<TreeNode*> nodeQueue;
        queue<int> depthQueue;
        nodeQueue.push(root);
        depthQueue.push(0);

        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();nodeQueue.pop();
            int depth = depthQueue.front();depthQueue.pop();

            if (node != NULL) {
            	// 维护二叉树的最大深度
                max_depth = max(max_depth, depth);

                // 由于每一层最后一个访问到的节点才是我们要的答案，因此不断更新对应深度的信息即可
                rightmostValueAtDepth[depth] =  node -> val;

                nodeQueue.push(node -> left);
                nodeQueue.push(node -> right);
                depthQueue.push(depth + 1);
                depthQueue.push(depth + 1);
            }
        }
