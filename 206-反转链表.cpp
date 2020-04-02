/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        //双指针的思想，一个一个迭代遍历，改变指向。但是注意！cur、pre本身都是链表！！
        ListNode* cur = NULL;
        ListNode* pre = head;
        while(pre != NULL){
            ListNode* temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;//cur逐渐从NULL一步一步倒推，变成head链表的反转。head链表本身没有改变。
        }
        return cur;//注意！返回的是cur！不是*cur，因为函数类型本身就是ListNode*了
    }
};
