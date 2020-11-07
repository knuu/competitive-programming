N, K = map(int, input().split())
S = input()
intervals = []

idx = 0
dirs = []
while idx < N:
    start = idx
    dirs.append([0, 1][S[idx] == "R"])
    while idx < N and S[idx] == S[start]:
        idx += 1
    intervals.append(idx - start)

assert(sum(intervals) == N)

def calc_ans(result_dirs):
    ans = N
    if result_dirs[0] == 0:
        ans -= 1
    for i in range(len(result_dirs)-1):
        now_dir, next_dir = result_dirs[i], result_dirs[i+1]
        if now_dir == 1 and next_dir == 0:
            ans -= 2
    if result_dirs[-1] == 1:
        ans -= 1
    return ans


rest = K
result_dirs = [dirs[0]]
for now_dir in dirs[1:]:
    if rest > 0 and now_dir == 1:
        result_dirs.append(0)
        rest -= 1
    else:
        result_dirs.append(now_dir)
if rest > 0 and dirs[0] == 1:
    result_dirs[0] = 0
left_ans = calc_ans(result_dirs)

rest = K
result_dirs = [dirs[0]]
for now_dir in dirs[1:]:
    if rest > 0 and now_dir == 0:
        result_dirs.append(1)
        rest -= 1
    else:
        result_dirs.append(now_dir)
if rest > 0 and dirs[0] == 0:
    result_dirs[0] = 1
right_ans = calc_ans(result_dirs)
print(max(left_ans, right_ans))
