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
    struct compare {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            return (l1->val > l2->val);
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (ListNode* list : lists) {
            if(list)   pq.push(list);
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(pq.size() > 0) {
            ListNode *node = pq.top();
            pq.pop();
            curr->next = node;
            curr = curr->next;
            if(node->next) 
                pq.push(node->next);
        }
        ListNode* merged_list = dummy->next;
        delete(dummy);
        return merged_list;
    }
};