import sys

if sys.version[0] == '2':
    input, range = raw_input, xrange


def main():
    S, L, R = map(int, input().split())
    print(max(min(S, R), L))


if __name__ == '__main__':
    main()
