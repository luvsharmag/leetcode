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
    // ListNode* sorted;
    // ListNode* insertionsort(ListNode* head){
    //     sorted = NULL;
    //     ListNode* curr = head;
    //     while(curr != NULL){
    //         ListNode* next = curr->next;
    //         insert(curr);
    //         curr = next;
    //     }
    //     head = sorted;
    //     return head;
    // }
    // void insert(ListNode* newnode){
    //     if(sorted == NULL || sorted->val > newnode->val){
    //         newnode->next = sorted;
    //         sorted = newnode;        
    //     }else{
    //         ListNode* curr = sorted;
    //         while(curr->next != NULL && curr->next->val < newnode->val){
    //             curr = curr->next;
    //         }
    //         newnode->next = curr->next;
    //         curr->next = newnode;
    //     }
    // }
    ListNode* merge(ListNode* first,ListNode* second){
        if(first == NULL){
            return second;
        }
        if(second == NULL){
            return first;        
        }
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        
        while(first != NULL && second != NULL){
            if(first->val < second->val){
                temp->next = first;
                temp = first;
                first = first->next;
            }else{
                temp->next = second;
                temp = second;
                second = second->next;
            }
        }
        while(first != NULL){
            temp->next = first;
            temp = first;
            first = first->next;
        }
        while(second != NULL){
            temp->next = second;
            temp = second;
            second = second->next;
        }
        ans = ans->next;
        return ans;
    }
    ListNode* getmiddle(ListNode* head){
       ListNode* slow = head;
       ListNode* fast = slow->next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;        
            slow = slow->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* middle = getmiddle(head);
        ListNode* first = head;
        ListNode* second = middle->next;
        middle->next = NULL;
        
        first = sortList(first);
        second = sortList(second);
        
        return merge(first,second);
    }
};