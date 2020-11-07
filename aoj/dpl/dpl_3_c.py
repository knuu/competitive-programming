def calc_largest_rect(hist):
    hist.append(0)
    stack = []
    left = [0] * len(hist)
    ans = 0
    for i, val in enumerate(hist):
        while stack and hist[stack[-1]] >= val:
            idx = stack.pop()
            ans = max(ans, (i - left[idx] - 1) * hist[idx])
        left[i] = stack[-1] if stack else -1
        stack.append(i)
    return ans


N = int(input())
H = [int(x) for x in input().split()]
print(calc_largest_rect(H))
