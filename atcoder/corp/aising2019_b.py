N = int(input())
A, B = map(int, input().split())
probs = [0] * 3
for p in map(int, input().split()):
    if p <= A:
        probs[0] += 1
    elif p <= B:
        probs[1] += 1
    else:
        probs[2] += 1
print(min(probs))
