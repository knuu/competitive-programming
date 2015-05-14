D = int(input())
C = 'x' * 14 + input() + input() + 'x' * 14
def goldenWeek(day):
    return 28 - ['o' * i in day for i in range(29)][::-1].index(True)

ans = goldenWeek(C)
for i in range(42):
    rec = 0
    while rec < D and i+rec < 42 and C[i+rec] == 'x':
        rec += 1
    if rec > 0:
        l = C[:i] + 'o' * rec + C[i+rec:]
        assert len(l) == 42, str(len(l))
        ans = max(ans, goldenWeek(C[:i] + 'o' * rec + C[i+rec:]))
print(ans)
