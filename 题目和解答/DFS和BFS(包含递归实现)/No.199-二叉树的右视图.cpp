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
