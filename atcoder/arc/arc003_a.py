gradePoints = {'A': 4, 'B': 3, 'C': 2, 'D': 1, 'F': 0}
N = int(input())
print(sum(gradePoints[r] for r in input()) / N)
