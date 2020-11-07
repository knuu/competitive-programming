T1, T2 = map(int, input().split())
A1, A2 = map(int, input().split())
B1, B2 = map(int, input().split())

taka = T1 * A1 + T2 * A2
aoki = T1 * B1 + T2 * B2
if taka == aoki:
    print("infinity")
    quit()
if taka > aoki:
    taka, aoki = aoki, taka
    A1, B1 = B1, A1
    A2, B2 = B2, A2
if A1 < B1:
    print(0)
    quit()
if A1 == B2:
    print(1)
    quit()
first_diff = A1 * T1 - B1 * T1
diff = aoki - taka
print(first_diff // diff * 2 + (first_diff % diff != 0))
