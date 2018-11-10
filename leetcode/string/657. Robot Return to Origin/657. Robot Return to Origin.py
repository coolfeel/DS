import numpy as np

class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        start = np.array([0, 0])
        dire = 'RLUD'
        op = np.array([[1, 0], [-1, 0], [0, 1], [0, -1]])
        for c in moves:
            start += op[dire.index(c)]
        if start[0] == 0 and start[1] == 0:
            return True
        else:
            return False
                
