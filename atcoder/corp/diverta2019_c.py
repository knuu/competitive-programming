N = int(input())

nb_na, b_na, nb_a, b_a = 0, 0, 0, 0
ans = 0
for _ in range(N):
    s = input()
    ans += s.count("AB")
    if s[0] == "B" and s[-1] == "A":
        b_a += 1
    elif s[0] == "B":
        b_na += 1
    elif s[-1] == "A":
        nb_a += 1
    else:
        nb_na += 1
if b_a > 0 and nb_a > 0:
    b_a += 1
    nb_a -= 1
if b_a > 0 and b_na > 0:
    b_a += 1
    b_na -= 1
ans += min(nb_a, b_na)

if b_a > 0:
    ans += b_a - 1

print(ans)
