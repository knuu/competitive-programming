import sys
def todec(s):
    roman_dic = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    ret, prev = 0, 0
    for i in reversed(s):
        d = roman_dic[i]
        if d < prev:
            ret -= d
        else:
            ret += d
        prev = d
    return ret

A = sys.stdin.read().split()
for a in A:
    print(todec(a))
