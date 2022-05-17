/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target)
    {
        //can be done by BFS too
        ArrayDeque<TreeNode> originalStack = new ArrayDeque<>();
        ArrayDeque<TreeNode> clonedStack = new ArrayDeque<>();
        TreeNode currOriginal = original, currCloned = cloned;
        
        while(!originalStack.isEmpty() || currOriginal != null){
            
            while(currOriginal != null){
                originalStack.push(currOriginal);
                clonedStack.push(currCloned);
                currOriginal = currOriginal.left;
                currCloned = currCloned.left;
            }
            
            currOriginal = originalStack.pop();
            currCloned = clonedStack.pop();
            
            if(currOriginal == target)
                return currCloned;
            
            currOriginal = currOriginal.right;
            currCloned = currCloned.right;
        }
        
        return null;
    }
}