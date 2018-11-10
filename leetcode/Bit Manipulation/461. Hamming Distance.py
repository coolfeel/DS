class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        cnt = 0
        for c in bin(x ^ y):
            if c == '1':
                cnt += 1
        return cnt
