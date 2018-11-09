class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        hash_map = {}
        S_len = len(S)
        J_len = len(J)
        for i in range(S_len):
            if S[i] not in hash_map.keys():
                hash_map[S[i]] = 0
            hash_map[S[i]] += 1
        sum = 0
        for i in range(J_len):
            if (J[i] not in hash_map.keys()):
                continue
            sum += hash_map[J[i]]
        return sum
