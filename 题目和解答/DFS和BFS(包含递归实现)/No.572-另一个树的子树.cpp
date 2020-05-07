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

//方法2
class Solution {
public:
    vector <int> sOrder, tOrder;
    int maxElement, lNull, rNull;

    void getMaxElement(TreeNode *o) {
        if (!o) return;
        maxElement = max(maxElement, o->val);
        getMaxElement(o->left);
        getMaxElement(o->right);
    }

    void getDfsOrder(TreeNode *o, vector <int> &tar) {
        if (!o) return;
        tar.push_back(o->val);
        if (o->left) getDfsOrder(o->left, tar);
        else tar.push_back(lNull);
        if (o->right) getDfsOrder(o->right, tar);
        else tar.push_back(rNull);
    }

    bool kmp() {
        int sLen = sOrder.size(), tLen = tOrder.size();
        vector <int> fail(tOrder.size(), -1);
        for (int i = 1, j = -1; i < tLen; ++i) {
            while (j != -1 && tOrder[i] != tOrder[j + 1]) j = fail[j];
            if (tOrder[i] == tOrder[j + 1]) ++j;
            fail[i] = j;
        }
        for (int i = 0, j = -1; i < sLen; ++i) {
            while (j != -1 && sOrder[i] != tOrder[j + 1]) j = fail[j];
            if (sOrder[i] == tOrder[j + 1]) ++j;
            if (j == tLen - 1) return true;
        }
        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        maxElement = INT_MIN;
        getMaxElement(s);
        getMaxElement(t);
        lNull = maxElement + 1;
        rNull = maxElement + 2;

        getDfsOrder(s, sOrder);
        getDfsOrder(t, tOrder);

        return kmp();
    }
};
