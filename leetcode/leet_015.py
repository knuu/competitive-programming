class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        counter = dict()
        for num in nums:
            counter[num] = counter.get(num, 0) + 1
        keys = sorted(counter.keys())
        ret = []
        if 0 in counter and counter[0] >= 3:
            ret.append([0, 0, 0])
        for i in xrange(len(keys)):
            for j in xrange(i+1, len(keys)):
                num = -(keys[i] + keys[j])
                if num != keys[i] and num != keys[j] and num in counter and keys[i] <= keys[j] <= num:
                    ret.append([keys[i], keys[j], num])
                elif num in [keys[i], keys[j]] and counter[num] >= 2:
                    ret.append([keys[i], num, keys[j]])
        return ret

if __name__ == '__main__':
    s = Solution()
    print(s.threeSum([-1, 0, 1, 2, -1, -4]))
