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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* curr = head, *prev = dummy;
        while(curr && curr -> next){
            ListNode* first_node = curr;
            ListNode* second_node = curr -> next;
            ListNode* next_curr = second_node -> next; 
            
            prev -> next = second_node;
            first_node -> next = next_curr;
            second_node -> next = first_node;
            
            prev = first_node;
            curr = next_curr;
        }
        ListNode* swapped_list = dummy -> next;
        delete(dummy);
        return swapped_list;
    }
};