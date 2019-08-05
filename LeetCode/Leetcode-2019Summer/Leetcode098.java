public class Leetcode098
{
    public static void main(String[] args) {
        //...
    }
    public boolean isValid(TreeNode root,Interger min,Interger max)
    {
        if(root==null) return true;
        if(min!=null &&root.val<=min) return false;
        if(max!=null &&root.val>=max ) return false;
        
        return isValid(root.left,min,root.val)&&
        isValid(root.right, root.val, max);
    }
}
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */