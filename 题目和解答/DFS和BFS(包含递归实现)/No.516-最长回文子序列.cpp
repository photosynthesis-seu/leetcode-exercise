/**方法一
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSametree(TreeNode* s, TreeNode* t){//判断两棵树是否相等
        if(s == nullptr&&t == nullptr){
            return true;//递归的返回条件，均空自然之前全相等，所以返回真。
        }
        return s&&t
                && s->val == t->val
                && isSametree(s->left,t->left)//递归判断
                && isSametree(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {//判断t是否是s的子树
        if(s == nullptr&&t == nullptr){
            return true;
        }
        if(s == nullptr&&t != nullptr){
            return false;
        }
        return isSametree(s,t)
            || isSubtree(s->left,t)//dfs
            || isSubtree(s->right,t);     
    }
};
