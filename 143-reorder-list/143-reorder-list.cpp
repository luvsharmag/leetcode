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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
            
            slow = slow->next;            
        }
        return slow;
    }
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return;
        }
        ListNode* first = head;
        ListNode* middle = findmiddle(head);
        ListNode* second = middle->next;
        middle->next = NULL;
        second = reverse(second);
        ListNode* prev1 = first;
        ListNode* curr1 = prev1->next;
        
        ListNode* prev2 = second;
        ListNode* curr2 = prev2->next;
        while(prev2 != NULL){
            prev1->next = prev2;
            prev2->next = curr1;
            prev1 = curr1;
            curr1 = curr1->next;
            prev2 = curr2;
            if(curr2 != NULL)
                curr2 = curr2->next;
        }
    }
};