/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int camera = 0;
    public enum NodeState { HAS_CAMERA, COVERED, NOT_COVERED };
    
    public int minCameraCover(TreeNode root) {
        return visitNodes(root) == NodeState.NOT_COVERED ? ++camera : camera;
    }
    
    public NodeState visitNodes(TreeNode root){
         // Base case - if there is no node then it's already covered
        if(root == null)    return NodeState.COVERED;
        
        
        NodeState leftNodeState = visitNodes(root.left);
        NodeState rightNodeState = visitNodes(root.right);
        
        // If Any one of the children is not covered then we must place a camera at current node
        if(leftNodeState == NodeState.NOT_COVERED || rightNodeState == NodeState.NOT_COVERED){
            camera++;
            return NodeState.HAS_CAMERA;
        }
        
        // If any one of left or right node has Camera then the current node is also covered
        if(leftNodeState == NodeState.HAS_CAMERA || rightNodeState == NodeState.HAS_CAMERA)
            return NodeState.COVERED;
        
        // If None of the children is covering the current node then ask it's parent to cover
        return NodeState.NOT_COVERED;
    }
}