class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        cnt, now = 0, len(s)-1
        while now >= 0 and s[now] != ' ':
            cnt += 1
            now -= 1
        return cnt
