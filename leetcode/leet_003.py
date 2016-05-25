class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret_len = 0
        counter = dict()
        left, right = 0, 0
        while True:
            while right < len(s):
                counter[s[right]] = counter.get(s[right], 0) + 1
                if counter[s[right]] > 1:
                    break
                right += 1
            ret_len = max(ret_len, right - left)
            if right == len(s):
                break
            while counter[s[right]] > 1:
                counter[s[left]] = counter[s[left]] - 1
                left += 1
            right += 1
        return ret_len

if __name__ == '__main__':
    print(Solution().lengthOfLongestSubstring("abcabcbb"))
    print(Solution().lengthOfLongestSubstring("b"))
    print(Solution().lengthOfLongestSubstring("pwwkew"))
