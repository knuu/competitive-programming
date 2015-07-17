range = xrange
input = raw_input

N = int(input())
A = [int(x) for x in input().split()]
volumes = set()
status = []
for i, a in enumerate(A):
    a_status = []
    while a:
        volumes.add(a)
        a_status.append(a)
        a >>= 1
    status.append(a_status)

ans = 1<<27

for volume in reversed(sorted(volumes)):
    a_ans = 0
    for a_status in status:
        for i, vol in enumerate(a_status):
            while vol < volume:
                vol <<= 1
                i += 1
            if vol == volume:
                a_ans += i
                break
        else:
            break
    else:
        ans = min(a_ans, ans)
print(ans)

                
    
    
