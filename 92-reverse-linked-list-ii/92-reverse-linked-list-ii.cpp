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
    ListNode* reverse(ListNode* &head){
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        left--;
        right++;
        ListNode* lp = head;
        int cnt = 1;
        while(cnt < left){
            lp = lp->next;
            cnt++;
        }     
        ListNode* rp = lp;
        while(cnt < right && rp != NULL){
            rp = rp->next;
            cnt++;
        }        
        ListNode* temp = lp;
        while(temp->next != rp && temp->next != NULL){
            temp = temp->next;
        }
        if(left == 0){
            temp->next = NULL;
            temp = head;
            lp = reverse(head);
            temp->next =rp;
            return lp;
        }
        temp->next = NULL;
        temp = lp->next;
        lp->next = reverse(lp->next);
       
        temp->next = rp;
        
        return head;
    }
};