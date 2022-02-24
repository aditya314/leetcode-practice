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
    ListNode* get_list_mid_and_split(ListNode* head){
        ListNode *slow = head, *fast = head, *prev_slow = NULL;
        while(fast && fast->next){
            prev_slow = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev_slow -> next = NULL;
        return slow;
    }
    ListNode* merge_lists(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        while(a && b){
            if(a -> val < b -> val){
                res -> next = a;
                a = a -> next;
            }
            else{
                res -> next = b;
                b = b -> next;
            }
            res = res -> next;
        }
        res -> next = (a != NULL) ? a : b;
        ListNode* merged_list = dummy -> next;
        delete(dummy);
        return merged_list;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head-> next)   return head;
        ListNode* mid = get_list_mid_and_split(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge_lists(left, right);
    }
};