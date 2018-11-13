class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        for i in range(len(A[0])):
            res_line = []
            for j in A:
                res_line.append(j[i])
            res.append(res_line)
        return res
