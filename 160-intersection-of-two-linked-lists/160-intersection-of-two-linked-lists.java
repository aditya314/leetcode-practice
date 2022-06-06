/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        //say A length = a + c, B length = b + c,
        //after switching pointer, pointer A will move another b + c steps,
        //pointer B will move a + c more steps, 
        //since a + c + b + c = b + c + a + c, it does not matter what value c is.
        //Pointer A and B must meet after a + c + b (b + c + a) steps. 
        //If c == 0, they meet at NULL.
        ListNode a = headA, b = headB;
        while(a != b){
            a = a == null? headB : a.next;
            b = b == null? headA : b.next;    
        }
        return a;
    }
}