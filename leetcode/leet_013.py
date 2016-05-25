class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        prev, ret = 0, 0
        for r in s[::-1]:
            if roman[r] >= prev:
                ret += roman[r]
                prev = roman[r]
            else:
                ret -= roman[r]
        return ret

if __name__ == '__main__':
    s = Solution()
    print(s.romanToInt('III'))
    print(s.romanToInt('IV'))
    print(s.romanToInt('CDXLIV'))
    print(s.romanToInt('CMXCIX'))
