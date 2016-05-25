class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = list()
        for s_i in s:
            if s_i in '([{':
                stack.append(s_i)
            else:
                if not stack:
                    return False
                top = stack.pop()
                if top + s_i not in '(){}[]':
                    return False
        return True if not stack else False

if __name__ == '__main__':
    s = Solution()
    print(s.isValid("()"))
    print(s.isValid("()[]{}"))
    print(s.isValid("(]"))
    print(s.isValid("([)]"))
