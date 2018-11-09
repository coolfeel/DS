class Solution:
    def toLowerCase(self, str):
        """
        :type str: str
        :rtype: str
        """
        res = ''
        for c in str:
            if c <= 'Z' and c >= 'A':
                res += chr(ord(c) + 32)
            else:
                res += c
        return res
