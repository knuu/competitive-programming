T, P = input(), input()
for i in range(len(T)):
    if T[i:].startswith(P):
        print(i)
