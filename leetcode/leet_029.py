class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == -1 << 31 and divisor == -1:
            return (1 << 31) - 1
