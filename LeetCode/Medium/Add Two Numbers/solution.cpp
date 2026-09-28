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
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode, *temp1 = l1, *temp2 = l2;
        int carry = 0;
        
        while(temp1 != nullptr && temp2 != nullptr){
            int sum = (temp1 -> val) + (temp2 -> val) + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp1 -> val = sum;
            temp -> next = temp1;
            temp = temp -> next;
            temp1 = temp1 -> next;
            temp2 = temp2-> next;
        }

        while(temp1 != nullptr){
           int sum = (temp1 -> val) + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp1 -> val = sum;            
            temp -> next = temp1;
            temp = temp -> next;
            temp1 = temp1 -> next;
        }

        while(temp2 != nullptr){
           int sum =(temp2 -> val) + carry;
            carry = sum / 10;           
            sum = sum % 10;
            temp2 -> val = sum;
            temp -> next = temp2;
            temp = temp -> next;
            temp2 = temp2 -> next;
        }

        if(carry == 1){
            ListNode *Carry = new ListNode(1);
            temp -> next = Carry;
        }        
        return dummyNode -> next;
    }
};