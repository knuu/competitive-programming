A, B = map(int, input().split())
diff = abs(A - B)
ans = diff // 10
diff %= 10
ans = ans + [0, 1, 2, 3, 2, 1, 2, 3, 3, 2][diff]

print(ans) 
