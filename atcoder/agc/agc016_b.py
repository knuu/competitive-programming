N = int(input())
A = [int(x) for x in input().split()]

A_set = sorted(set(A))
if len(A_set) == 1:
    print("Yes" if A_set[0] <= N // 2 or A_set[0] == N - 1 else "No")
elif len(A_set) == 2 and A_set[0] + 1 == A_set[1]:
    cnt_min = A.count(A_set[0])
    cnt_max = N - cnt_min
    if cnt_min <= A_set[0] and cnt_min + 1 <= A_set[1] <= cnt_min + cnt_max // 2:
        print("Yes")
    else:
        print("No")
else:
    print("No")
