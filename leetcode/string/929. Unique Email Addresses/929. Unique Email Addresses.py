class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        res_sets = []
        for email in emails:
            res = ''
            add_index = email.index('+')
            at_index = email.index('@')
            res = email[: add_index] + email[at_index :]
            at_index = res.index('@')
            a = res[: at_index].replace('.', '')
            r = a + res[at_index :]
            res_sets.append(r)
        return len(set(res_sets))
