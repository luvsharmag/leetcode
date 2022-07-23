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
    void insertAttail(ListNode* &head,ListNode* &tail,int data){
        ListNode* temp = new ListNode(data);
        if(head == NULL){            
            head = temp;
            tail = temp;
            return;
        }else{
            tail -> next = temp;
            tail = temp;
        }
    }
    ListNode* addit(ListNode* first,ListNode* second){
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){
                val1 = first->val;
            }
            int val2 = 0;
            if(second != NULL){
                val2 = second->val;            
            }
            int sum = val1+val2+carry;
            int digit = sum % 10;
            
            insertAttail(head,tail,digit);
            carry = sum/10;
            
            if(first != NULL){
                first = first->next;
            }
            if(second != NULL){
                second = second->next;
            }
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans = addit(l1,l2);    
        ans = reverse(ans);
        return ans;
    }
};