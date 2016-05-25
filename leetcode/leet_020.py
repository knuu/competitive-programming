class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        L = len(s)
        dp = [[False] * L for _ in xrange(L)]
        for i in xrange(L-1):
            if s[i:i+2] in ['()', '[]', '{}']:
                dp[i][i+1] = True
        for w in xrange(4, L+1):
            for left in xrange(L-w+1):
                right = left + w - 1
                if s[left] + s[right] in ['()', '[]', '{}'] and dp[left+1][right-1]:
                    dp[left][right] = True
                    continue
                for mid in xrange(left+1, right-1):
                    if dp[left][mid] and dp[mid+1][right]:
                        dp[left][right] = True
                        break
        return dp[0][L-1]

if __name__ == '__main__':
    s = Solution()
    print(s.isValid("()"))
    print(s.isValid("()[]{}"))
    print(s.isValid("(]"))
    print(s.isValid("([)]"))
