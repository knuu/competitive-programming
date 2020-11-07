from collections import Counter
H, W = map(int, input().split())
cnt4, cnt2, cnt1 = 0, 0, 0
for v in Counter(''.join(input() for _ in range(H))).values():
    if v % 4 == 0:
        continue
    elif v % 2 == 0:
        cnt2 += 1
    else:
        cnt1 += 1
        if (v - 1) % 4 != 0:
            cnt2 += 1
odd = (H % 2 == 1) + (W % 2 == 1)
if odd == 2:
    if cnt1 <= 1 and cnt2 <= (H + W - 2) // 2:
        print("Yes")
    else:
        print("No")
elif odd == 1 and H % 2 == 1:
    if cnt1 == 0 and cnt2 <= W // 2:
        print("Yes")
    else:
        print("No")
elif odd == 1 and W % 2 == 1:
    if cnt1 == 0 and cnt2 <= H // 2:
        print("Yes")
    else:
        print("No")
else:
    if cnt1 == 0 and cnt2 == 0:
        print("Yes")
    else:
        print("No")
