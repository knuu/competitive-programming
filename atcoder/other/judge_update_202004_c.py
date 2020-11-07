import sys
import itertools


if sys.version[0] == '2':
    input, range = raw_input, xrange


def main():
    a, b, c = map(int, input().split())
    ans = 0
    for p in itertools.permutations(range(a+b+c)):
        nums = p[:a], p[a:a+b], p[a+b:]
        flag = True
        for i, num in enumerate(nums):
            for j, x in enumerate(num):
                if i > 0 and x < nums[i-1][j]:
                    flag = False
                if j > 0 and x < num[j-1]:
                    flag = False
                    break
        ans += flag
    print(ans)


if __name__ == '__main__':
    main()
