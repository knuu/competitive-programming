N, K = map(int, input().split())
ans = 0
group = 0
for _ in range(K):
    mat = [int(x) for x in input().split()]
    n_mat, mat = mat[0], mat[1:]
    if mat[0] == 1:
        for i in range(n_mat-1):
            if mat[i] + 1 != mat[i+1]:
                ans += n_mat - i - 1
                group += n_mat - i - 1
                break
        group += 1
    else:
        ans += n_mat - 1
        group += n_mat
ans += group - 1
print(ans)
