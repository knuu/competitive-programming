board = sum([list(input()) for _ in range(3)], [])
assert(board[4] == '1')
rest = list(range(2, 10))
clock = [1, 2, 5, 0, -1, 8, 3, 6, 7]
cclock = [3, 0, 1, 6, -1, 2, 7, 8, 5]
for start in [1, 3, 5, 7]:
    for next_idx in [clock, cclock]:
        now = start
        ans = board[:]
        for i in rest:
            if board[now] != '?' and board[now] != str(i):
                break
            ans[now] = str(i)
            now = next_idx[now]
        else:
            assert(all(x != '?' for x in ans))
            assert(len(set(ans)) == 9)
            ans = ''.join(map(str, ans))
            print(*[ans[:3], ans[3:6], ans[6:]], sep='\n')
            quit(0)
