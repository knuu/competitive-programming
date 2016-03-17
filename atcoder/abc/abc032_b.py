s, k = input(), int(input())
print(0 if len(s) < k else len(set(s[i:i+k] for i in range(len(s)-k+1))))
