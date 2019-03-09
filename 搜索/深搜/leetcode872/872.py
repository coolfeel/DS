# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        seq1 = []
        seq2 = []
        self.get_seq(root1, seq1)
        self.get_seq(root2, seq2)
        return seq1 == seq2
    
    
    def get_seq(self, root, seq):
        if root == None:
            return
        if root.left != None:
            self.get_seq(root.left, seq)
        if root.right != None:
            self.get_seq(root.right, seq)
        if root.left == None and root.right == None:
            seq.append(root.val)
            