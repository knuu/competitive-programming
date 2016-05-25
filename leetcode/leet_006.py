class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        ret = [[] for _ in xrange(numRows)]
        row, dir = 0, 1
        for s_i in s:
            ret[row].append(s_i)
            row += dir
            if row < 0:
                row = abs(row)
                dir *= -1
            elif row >= numRows:
                row = 2 * numRows - row - 2
                dir *= -1
        return ''.join(''.join(r) for r in ret)

if __name__ == '__main__':
    print(Solution().convert("PAYPALISHIRING", 3))
