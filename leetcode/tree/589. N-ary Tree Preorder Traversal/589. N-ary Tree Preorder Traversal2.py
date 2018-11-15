"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if root == None:
            return []
        stack = [root]
        out = []
        while stack:
            p = stack.pop()
            out.append(p.val)
            stack.extend(p.children[: : -1]) #因为栈是先进后出，所有反向进。。
        return out
    
       
