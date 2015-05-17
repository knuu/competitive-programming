A, B = map(int, input().split())
for i in range(A, B+1):
    if '3' in str(i) or i % 3 == 0:
        print(i)
