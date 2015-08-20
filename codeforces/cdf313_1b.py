range = xrange
input = raw_input

def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

def str_eq(s1, s2):
    len_s1, len_s2 = len(s1), len(s2)
    if s1 == s2:
        memo[(s1, s2)] = memo[(s2, s1)] = True
        return True

    if len_s1 == 1:
        memo[(s1, s2)] = memo[(s2, s1)] = False
        return False
    if (s1, s2) in memo:
        return memo[(s1, s2)]

    if len_s1 % 2 == 1:
        return False
    
    s11, s12 = s1[:len_s1//2], s1[len_s1//2:]
    s21, s22 = s2[:len_s2//2], s2[len_s2//2:]

    if str_eq(s11, s21) and str_eq(s12, s22):
        memo[(s1, s2)] = memo[(s2, s1)] = True
        return True
    if str_eq(s11, s22) and str_eq(s12, s21):
        memo[(s1, s2)] = memo[(s2, s1)] = True
        return True
    memo[(s1, s2)] = memo[(s2, s1)] = False
    return False    

S1 = read_line(str)
S2 = read_line(str)
memo = dict()
print('YES' if str_eq(S1, S2) else 'NO')
