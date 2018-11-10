class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        x = 0
        y = 0
        for op in moves:
            if op == 'U':
                y += 1
            elif op == 'R':
                x += 1
            elif op == 'L':
                x -= 1
            elif op == 'D':
                y -= 1
        return x == 0 and y == 0
                
