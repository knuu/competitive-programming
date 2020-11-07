L = int(input())
orig_A = [int(input()) for _ in range(L)]
A = [x % 2 for x in orig_A]
rev_A = [x ^ 1 for x in A]

sum_A = sum(A)
sum_rev_A = sum(rev_A)
n_zero = sum(x == 0 for x in orig_A)
print(sum_A, sum_rev_A, n_zero)
ans = min(sum_A + 2 * n_zero, sum_rev_A)
odd = even = zero = 0
for x, orig_x in zip(A, orig_A):
    if orig_x == 0:
        zero += 1
    elif x:
        odd += 1
    else:
        even += 1

    ans = min(ans, sum_rev_A - even + odd + zero)

odd = even = zero = 0
for i in reversed(range(L)):
    x, orig_x = A[i], orig_A[i]
    if orig_x == 0:
        zero += 1
    elif x:
        odd += 1
    else:
        even += 1
    print(i, even, odd, zero)
    ans = min(ans, sum_rev_A - even + odd + zero)
print(ans)
