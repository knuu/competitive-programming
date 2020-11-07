import sys

if sys.version[0] == '2':
    input, range = raw_input, xrange


def main():
    N = int(input())
    balls = {"R": [], "B": []}
    for _ in range(N):
        X, C = input().split()
        balls[C].append(int(X))
    for color in ["R", "B"]:
        for x in sorted(balls[color]):
            print(x)


if __name__ == '__main__':
    main()
