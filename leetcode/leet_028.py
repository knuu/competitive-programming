class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle:
            return 0
        haystack, needle = haystack + "\0", needle + "\0"
        i, L = 0, len(haystack)
        while haystack[i] != "\0":
            if haystack[i] == needle[0]:
                start, now = i, 0
                while haystack[i] == needle[now] and haystack[i] != "\0" and needle[now] != "\0":
                    i += 1
                    start += 1
                else:
                    if needle[now] == "\0":
                        return start
            else:
                i += 1
        return -1
