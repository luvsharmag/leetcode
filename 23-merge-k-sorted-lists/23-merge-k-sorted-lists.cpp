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
    ListNode* merge(ListNode* first,ListNode* second){
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        
        ListNode* first = lists[0];
        ListNode* second = lists[1];
        int i = 1;
        while(i < lists.size()){
            first = merge(first,second);
            second = lists[++i];
        }
        return first;
    }
};