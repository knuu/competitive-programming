S = input()
c_cnt, w_cnt = S.count('c'), S.count('w')
print(min(c_cnt - 1, w_cnt))
