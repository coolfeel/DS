class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        a = sorted(nums1 + nums2)
        a_len = len(a)
        if a_len % 2 == 1:
            return a[a_len // 2]
        else:
            return (a[a_len // 2] + a[a_len // 2 - 1]) / 2
        
