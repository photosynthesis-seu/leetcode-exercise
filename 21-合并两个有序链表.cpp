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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(1);
        ListNode* res = result;//最后的结果是从result链表第二个节点开始的，这样做可以每次从result->next添加节点
        if(l1 != NULL && l2 == NULL){
            return l1;
        }
        if(l1 == NULL && l2 != NULL){
            return l2;
        }
        //注意这里的判断条件必须用&&，如果用或的话，NULL无法和另一个链表节点的值比大小
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                result->next = l1;
                result = result->next;
                l1 = l1->next;
            }
            else{
                result->next = l2;
                result = result->next;
                l2 = l2->next;
            }
            result->next = l1 == NULL? l2:l1;//在这一步再将更长一些的链表补在result后面
        }
        return res->next;
    }
};
