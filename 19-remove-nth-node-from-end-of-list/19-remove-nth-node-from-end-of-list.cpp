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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            delete(head);
            return NULL;
        }
        ListNode* temp = head;
        temp = reverse(temp);
        
        ListNode* prev = NULL;
        ListNode* curr = temp;
        int count = 1;
        while(count < n){
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(curr == temp){
            temp = temp->next;
            delete(curr);
            temp = reverse(temp);
            return temp;
        }
        if(prev != NULL)
        prev->next = curr->next;
        ListNode* deletionNode = curr;
        if(curr != NULL)
        curr->next = NULL;
        delete(deletionNode);
        
        temp = reverse(temp);
        return temp;
    }
};