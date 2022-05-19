/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *dummy=new ListNode(0);
        ListNode *temp=dummy;
        int first,second,carry=0;
        while(l1 || l2 ||carry){
            // int value=0;
            if(l1){
                first=l1->val;
                l1=l1->next;
            }
            else{
                first=0;
            }
            if(l2){
                second=l2->val;
                l2=l2->next;
            }
            else{
                second=0;
            }
            int sum=first+second+carry;
            temp->next=new ListNode(sum%10);
            carry=sum/10;
            temp=temp->next;
        }
        return dummy->next;
    }
};