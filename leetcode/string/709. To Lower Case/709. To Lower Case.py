class Solution:
    def toLowerCase(self, str):
        """
        :type str: str
        :rtype: str
        """
        res = ''
        for i  in range(len(str)):
            if str[i] <= 'Z' and str[i] >= 'A':
                res += chr(ord(str[i]) + 32)
            else:
                res += str[i]
        return res
