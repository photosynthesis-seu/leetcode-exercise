/**
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
    int depth;
    vector<vector<int>> res;
    queue<TreeNode*> track;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> layer;
        layer.push_back(root->val);
        res.push_back(layer);
        track.push(root);
        while(!track.empty()){
            layer.clear();
            int len = track.size();
            for(int i=0;i<len;i++){
                auto node = track.front();
                track.pop();
                if(node->left != NULL){
                    track.push(node->left);
                    layer.push_back(node->left->val);
                }
                if(node->right != NULL){
                    track.push(node->right);
                    layer.push_back(node->right->val);
                }
            }
            if(layer.size() != 0){
                res.push_back(layer);
            }
        }
        return res;
    }
};
