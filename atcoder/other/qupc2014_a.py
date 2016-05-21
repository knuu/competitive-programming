subjects, min_sub, students, min_st = map(int, input().split())
tests = [[int(x) for x in input().split()] for _ in range(students)]
score = 0
for s in range(101):
    passed = 0
    for i in range(students):
        if sum(p >= s for p in tests[i]) >= min_sub:
            passed += 1
    if passed >= min_st:
        score = max(score, s)
print(score)
