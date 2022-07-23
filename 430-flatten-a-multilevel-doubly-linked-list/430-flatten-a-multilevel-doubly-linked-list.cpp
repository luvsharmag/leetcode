/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while(temp != NULL){
            while(temp != NULL && temp->child == NULL){
                temp = temp->next;
            }    
            if(temp == NULL){
                return head;
            }
            Node* next = temp->next;
            temp->next = temp->child;
            temp->child->prev = temp;
            temp->child = NULL;    
            temp->next = flatten(temp->next);
            while(temp->next != NULL){
                temp = temp->next;
            }
            if(next != NULL)
            next->prev = temp;
            temp->next = next;
        }
        return head;
    }
};