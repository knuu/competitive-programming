def read_data():
    N = int(input())
    S = [input() for _ in range(N)]
    return N, S

def solve(N, S):
    sentinel = chr(ord('z')+1)
    S = [s + sentinel for s in S]
    ret = ''
    cursor = [0] * N

    while True:
        next_c, next_i = sentinel, 0
        for i, s in enumerate(S):
            c = s[cursor[i]:]
            if c < next_c:
                next_c, next_i = c, i
        if next_c == sentinel:
            return ret
        else:
            ret += next_c[0]
            cursor[next_i] += 1

if __name__ == '__main__':
    N, S = read_data()
    print(solve(N, S))
    
