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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *front_k_node = nullptr, *end_k_node = nullptr, *curr_node = head;
        int curr_len = 0;
        while(curr_node){
            if(end_k_node)  
                end_k_node = end_k_node -> next;
            curr_len++;
            if(curr_len == k){
                front_k_node = curr_node;
                end_k_node = head;
            }
            curr_node = curr_node -> next;
        }
        swap(front_k_node -> val, end_k_node -> val);
        return head;
    }
};