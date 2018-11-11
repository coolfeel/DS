class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        res = []
        for i in range(left, right + 1):
            flag = 1
            tmp = i
            while i:
                n = i % 10
                if n == 0:
                    flag = 0
                    break
                if tmp % n:
                   flag = 0
                i = i // 10
            if flag:
                res.append(tmp)
        return res
