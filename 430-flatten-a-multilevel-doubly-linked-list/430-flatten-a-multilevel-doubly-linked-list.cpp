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
private:
    Node* flattenDFS(Node* prev_head, Node* curr_head){
        if(!curr_head)  return prev_head;
        prev_head -> next = curr_head;
        curr_head -> prev = prev_head;
        
        Node* next_head = curr_head -> next;
        Node* child_head = flattenDFS(curr_head, curr_head -> child);
        curr_head -> child = NULL;
        return flattenDFS(child_head, next_head);
    }
public:
    Node* flatten(Node* head) {
        if(!head)   return head;
        Node* dummy = new Node();
        flattenDFS(dummy, head);
        Node* list_head = dummy -> next;
        list_head -> prev = NULL;
        dummy -> next = NULL;
        delete(dummy);
        return list_head;
    }
};