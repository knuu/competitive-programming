class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.lstrip()
        sign = 1
        if len(str) and not str[0].isdigit():
            if str[0] == "-":
                sign = -1
            elif str[0] != '+':
                return 0
            str = str[1:]
        ret = 0
        for s in str:
            if not s.isdigit():
                break
            ret = 10 * ret + (ord(s) - ord('0'))
        ret *= sign
        return min(max(ret, -2**31), -1+2**31)
