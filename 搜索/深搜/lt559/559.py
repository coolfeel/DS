"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if root == None:
            return 0
        self.result = 0
        self.dfs(root, 1)
        return self.result
    
    def dfs(self, root, depth):
        self.result = max(self.result, depth)
        for child in root.children:
            self.dfs(child, depth + 1)