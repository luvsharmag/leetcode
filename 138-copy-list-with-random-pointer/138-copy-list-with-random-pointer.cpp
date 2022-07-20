/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAttail(Node* &head,Node* &tail,int data){
        Node* temp = new Node(data);    
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* temp = head;
        Node* cloneNode = NULL;
        Node* clonehead = cloneNode;
        Node* clonetail = NULL;
        while(temp != NULL){
            insertAttail(clonehead,clonetail,temp->val);
            temp = temp->next;
        }
        temp = head;
        Node* clonetemp = clonehead;
        map<Node*,Node*> oldtonew;
        while(temp != NULL){
            oldtonew[temp] = clonetemp;
            temp = temp->next;
            clonetemp = clonetemp->next;
        }
        temp = head;
        clonetemp = clonehead;
        while(temp != NULL){
            clonetemp->random = oldtonew[temp->random];
            clonetemp = clonetemp->next;
            temp = temp->next;
        }
        return clonehead;
    }
};