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
    public int deepestLeavesSum(TreeNode root) {
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        int levelSum = 0;
        while(!q.isEmpty()){
            int levelSize = q.size();
            levelSum = 0;
            while(levelSize-- > 0){
                TreeNode currNode = q.remove();
                levelSum += currNode.val;
                if(currNode.left != null)
                    q.add(currNode.left);
                if(currNode.right != null)
                    q.add(currNode.right);
            }
        }
        return levelSum;
    }
}