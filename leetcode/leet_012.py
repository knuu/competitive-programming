class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        roman = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M', 5000: ''}
        ret = ''
        for i, s in enumerate(str(num)[::-1]):
            if s in ['4', '9']:
                ret = roman[10**i] + roman[(int(s)+1)*10**i] + ret
            elif s != '0':
                ret = roman[5 * 10**i] * (int(s) >= 5) + roman[10**i] * (int(s) % 5) + ret
        return ret

if __name__ == '__main__':
    s = Solution()
    for i in range(20):
        print(i+1, s.intToRoman(i+1))
