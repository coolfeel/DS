class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        results = []
        for str in A:
            rev_res = []
            rev_str = str[: : -1]
            for c in rev_str:
                if c == 0:
                    rev_res.append(1)
                else:
                    rev_res.append(0)
            results.append(rev_res)
        return results
