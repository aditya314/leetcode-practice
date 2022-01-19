/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* get_intersection(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow ->next;
            fast = fast -> next -> next;
            if(slow == fast)    return slow;
        }
        return nullptr;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)   return head;
        ListNode* intersection_node = get_intersection(head);
        if(!intersection_node)    return nullptr;
        ListNode* ptr1 = head;
        ListNode* ptr2 = intersection_node;
        while(ptr1 != ptr2){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return ptr1;
    }
};