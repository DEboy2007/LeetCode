class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        prefix = ""
        least_len = len(strs[0])
        for i in strs:
            if len(i) < least_len:
                least_len = len(i)

        for i in range(least_len):
            alphabet = strs[0][i]
            flag = True
            for j in strs:
                if j[i] != alphabet:
                    flag = False
            if not flag:
                return prefix
            else:
                prefix += j[i]
        
        return prefix
                
        