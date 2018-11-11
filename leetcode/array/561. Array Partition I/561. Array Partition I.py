class Solution:
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums) // 2
        res = sorted(nums)
        sum = 0
        tmp = 0
        for i in range(n):
            sum += res[tmp]
            tmp += 2
        return sum
