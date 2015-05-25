#!/usr/bin/python3
def maxXor(l, r):
    ret = 0
    for i in range(l, r+1):
        for j in range(i, r+1):
            ret = max(ret, i^j)
    return ret
if __name__ == '__main__':
    l = int(input())
    r = int(input())
    print(maxXor(l, r))
