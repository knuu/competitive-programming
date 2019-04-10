N = int(input())
A = [int(x) for x in input().split()]

cnt4 = len([x for x in A if x % 4 == 0])
cnt2 = len([x for x in A if x % 2 == 0]) - cnt4
if 2 * cnt4 + cnt2 >= N or (N % 2 == 1 and cnt4 >= N // 2):
    print("Yes")
else:
    print("No")
