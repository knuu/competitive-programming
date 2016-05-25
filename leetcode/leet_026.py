class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = 1
        prev = -1
        for i, num in enumerate(nums):
            if i and prev != num:
                nums[ret], nums[i] = nums[i], nums[ret]
                ret += 1
            prev = num
        return ret
