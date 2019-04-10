N = int(input())
def digit_sum(s):
    return sum(int(x) for x in str(s))
ans = 10 ** 9
for i in range(1, N):
    ans = min(ans, digit_sum(i) + digit_sum(N - i))
print(ans)
