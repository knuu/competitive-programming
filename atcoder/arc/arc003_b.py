N = int(input())
print('\n'.join([s[::-1] for s in sorted([input()[::-1] for _ in range(N)])]))
