/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        Node dummyHead = new Node(0); // dummyHead of the same-level-connection
        Node prevNode = dummyHead, // prevNode of the same-level-connection, starts with dummy
                currRoot = root; //curr parent of the connection, one level above
        while(currRoot != null){
            if(currRoot.left != null){
                prevNode.next = currRoot.left;
                prevNode = prevNode.next;
            }
            if(currRoot.right != null){
                prevNode.next = currRoot.right;
                prevNode = prevNode.next;
            }
            currRoot = currRoot.next;
            if(currRoot == null){
                prevNode = dummyHead;
                currRoot = dummyHead.next; // new root is one level below next to dummyHead
                dummyHead.next = null; //remove dummy node
            }
        }
        return root;
    }
}