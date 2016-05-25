class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        used = set()
        N = len(nums)
        ret = []
        for i in xrange(N):
            for j in xrange(i+1, N):
                for k in xrange(j+1, N):
                    if nums[i] + nums[j] + nums[k] == 0 and (nums[i], nums[j], nums[k]) not in used:
                        ret.append([nums[i], nums[j], nums[k]])
                        used.add((nums[i], nums[j], nums[k]))
        return ret

if __name__ == '__main__':
    s = Solution()
    print(s.threeSum([-1, 0, 1, 2, -1, -4]))
