class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = -1 if x < 0 else 1
        ret = sign * int(str(abs(x))[::-1])
        return ret if -2**31 <= ret < 2**31 else 0