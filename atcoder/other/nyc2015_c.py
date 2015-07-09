def main():
    s, t = input(), input()

    if s[0] != t[0]:
        print('No')
        return

    for i in range(1, len(t)):
        if i >= len(s) or t[i] != s[i]:
            if t[i] != s[i-1]:
                s = s[:i] + t[i] + s[i:]
            else:
                j = i - 1
                while j >= 0 and t[i] == s[j]:
                    j -= 1
                if j < 0: break
                s = s[:j+1] + t[i] + s[j+1:]

    print('Yes' if s == t else 'No')

if __name__ == '__main__':
    main()
