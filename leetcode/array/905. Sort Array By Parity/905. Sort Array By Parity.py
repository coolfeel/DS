class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        list_even = []
        list_odd = []
        for i in A:
            if i % 2 == 0:
                list_even.append(i)
            else:
                list_odd.append(i)
        a = list_even + list_odd
        return a
