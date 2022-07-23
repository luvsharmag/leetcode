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
    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        ListNode* temp = head;
        int i = 0;
        int ans = 0;
        while(temp != NULL){
            int value1 = pow(2,i);
            ans += (temp->val*value1);
            temp = temp->next;
            i++;
        }
        return ans;
    }
};