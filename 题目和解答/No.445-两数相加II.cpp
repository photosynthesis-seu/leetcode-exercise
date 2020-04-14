//自己的方法太菜，无法通过全部测试（整数移除）
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long int num1=0,num2=0,res=0;
        while(l1->next != NULL){
            num1 = num1*10 + l1->val;
            l1 = l1->next;
        }
        num1 = num1*10 + l1->val;
        while(l2->next != NULL){
            num2 = num2*10 + l2->val;
            l2 = l2->next;
        }
        num2 = num2*10 + l2->val;
        res = num1 + num2;
        int count = 0;
        vector<int> temp(100); 
        ListNode* ans = new ListNode(0);
        ListNode* result=ans;
        if(res == 0){
            return result;
        }
        while(res!=0){
            //vector<int> temp;
            temp[count]=res%10;
            count++;
            res = res/10;
        }
        
       for(int j = count-1;j>=0;j--){
            ListNode* cur = new ListNode;
            cur->val = temp[j];
            cur->next = NULL;
            result->next = cur;
            result = result->next;
        }
        return ans->next;
    }
};
