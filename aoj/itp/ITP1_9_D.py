s = input()
q = int(input())
insts = [input().split() for _ in range(q)]

for inst in insts:
    a, b = int(inst[1]), int(inst[2]) + 1
    if inst[0] == "replace":
        p = inst[3]
        s = s[:a] + p + s[b:]
    elif inst[0] == "reverse":
        s = s[:a] + s[a:b][::-1] + s[b:]
    elif inst[0] == "print":
        print(s[a:b])
