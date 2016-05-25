class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        parset = [set() for _ in xrange(n+1)]
        parset[0].add('')
        for i in range(n):
            for par in parset[i]:
                parset[i+1].add('('+par+')')
            if i > 0:
                for j in xrange(1, i+1):
                    for par1 in parset[j]:
                        for par2 in parset[i+1-j]:
                            parset[i+1].add(par1+par2)
        return list(parset[n])
