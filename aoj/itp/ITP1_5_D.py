n = int(input())

ans = []
i = 1

while True:
    """CHECK_NUM"""
    x = i
    if x % 3 == 0:
        ans.append(str(i))
    else:
        while True:
            """INCLUDE3"""
            if x % 10 == 3:
                ans.append(str(i))
                break

            x = int(x / 10)
            
            if x != 0: 
                continue
            else: 
                break
    i += 1
    if i <= n:
        continue
    else:
        break

print(" " + " ".join(ans))

