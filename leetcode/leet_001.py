class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_with_index = [(num, idx) for idx, num in enumerate(nums)]
        nums_with_index.sort()
        right = len(nums)-1
        for i in xrange(len(nums)):
            while right > 0 and nums_with_index[i][0] + nums_with_index[right][0] > target:
                right -= 1
            if nums_with_index[i][0] + nums_with_index[right][0] == target:
                return [nums_with_index[i][1], nums_with_index[right][1]]
        return 0
