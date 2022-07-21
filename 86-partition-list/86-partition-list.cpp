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
    void insertAttail(ListNode* &head,ListNode* &tail,int data){
        ListNode* temp = new ListNode(data);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* lowh = NULL;
        ListNode* lowt = NULL;
        ListNode* highh = NULL;
        ListNode* hight = NULL;
        while(temp != NULL){
            if(temp->val < x){
                insertAttail(lowh,lowt,temp->val);
            }else{
                insertAttail(highh,hight,temp->val);
            }
            temp = temp->next;
        }
        if(lowt != NULL){
            lowt->next = highh;
            return lowh;
        }else{
            return highh;
        }
    }
};