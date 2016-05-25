class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        ret = 0
        for i, num in enumerate(nums):
            if num != val:
                nums[ret], nums[i] = nums[i], nums[ret]
                ret += 1
        return ret
