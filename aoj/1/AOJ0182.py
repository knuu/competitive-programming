while True:
    n = int(input())
    if n == 0: break
    beakers = list(map(int, input().split()))
    m = max(beakers)
    beakers.remove(m)
    beakersum = [m]
    if not beakers:
        print("YES")
        continue

    if sum(beakers) < m:
        print("NO")
        continue
    elif sum(beakers) == m:
        print("YES")
        continue

    flag = False
    for b in beakers:
        if b == m:
            flag = True
            break
        tmp = [bks + b for bks in beakersum if bks + b <= m]
        if m in tmp:
            flag = True
            break
#        beakersum.append(b)
        beakersum.extend(tmp)
    
    if (m in beakersum) or flag:
        print("YES")
    else:
        print("NO")
            
        
