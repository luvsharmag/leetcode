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
private:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next;
            if(fast!=NULL) fast = fast->next;
            slow = slow->next;
        }
        // cout<<slow->val;
        return slow;
    }
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
    bool isPalindrome(ListNode* head) {
        // vector<int> arr;
        // ListNode* curr = head;
        // while(curr != NULL){
        //     arr.push_back(curr->val);
        //     curr = curr->next;
        // }
        // int s = 0,e = arr.size() - 1;
        // while(s <= e){
        //     if(arr[s] == arr[e]){
        //         s++;
        //         e--;
        //     }else{
        //         return false;
        //     }
        // }
        // return true;
        // apr2
        // find size
        if(head->next == NULL){
            return true;
        }
        // if(headhead->val != head->next->val){
        //     return false;
        // }
        ListNode* middle = getMiddle(head);
        
        ListNode* temp = middle->next;
        middle->next = reverse(temp);
        
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        
        while(head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        temp = middle->next;
        middle->next = reverse(temp);
        
        return true;
    }
};