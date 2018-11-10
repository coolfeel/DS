class Solution:
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        mapping_list = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        le = 'abcdefghijklmnopqrstuvwxyz'
        results = []
        for str in words:
            res = ''
            for c in str:
                res += mapping_list[le.index(c)]
            results.append(res)
        return len(set(results))
