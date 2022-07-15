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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    public:
    void insertAttail(ListNode* &head,ListNode* &tail,int data){
        if(head == NULL){
            ListNode* temp = new ListNode(data);
            head = temp;
            tail = temp;
            return;
        }else{
            ListNode* temp = new ListNode(data);
            tail -> next = temp;
            tail = temp;
        }
    }
    ListNode* sum(ListNode* first,ListNode* second){
        int carry = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){
                val1 = first->val;
            }
            int val2 = 0;
            if(second != NULL){
                val2 = second->val;
            }
            int sum = carry + val1 + val2;
            
            int digit = sum % 10;
            
            insertAttail(head,tail,digit);
            
            carry = sum /10;
            if(first != NULL)
                first = first->next;
            if(second != NULL)
                second = second->next;
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = sum(l1,l2);        
        return ans;
    }
};