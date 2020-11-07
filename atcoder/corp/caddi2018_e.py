def main() -> None:
    N = int(input())
    A = [int(x) for x in input().split()]
    rev_A = A[:]
    left = [-1] * N
    left_cnt = [0] * N
    A_left = [A[0]]
    for i in range(1, N):
        if rev_A[i-1] < rev_A[i]:
            cnt = 0
            while rev_A[i-1]
            pass
        elif rev_A[i-1] < rev_A[i] * 4:
            now = i-1
            while left[now] != -1:
                now = left[now]
            left[i] = now
        A_left.append(A[i])




            left[i] = i-1
        else:
            pass



    ans = 10 ** 9
    for i in range(N + 1):
        A = AA[:]
        cnt = 0
        if i > 0:
            A[i-1] *= -2
            cnt += 1
            for j in reversed(range(i-1)):
                A[j] *= -2
                cnt += 1
                while A[j] > A[j+1]:
                    A[j] *= 4
                    cnt += 2
        for j in range(i+1, N):
            while A[j-1] > A[j]:
                A[j] *= 4
                cnt += 2
        print(i, cnt, A)
        ans = min(ans, cnt)
    print(ans)


if __name__ == '__main__':
    main()
