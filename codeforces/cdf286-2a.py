def main():
    s = input()
    for i in range(len(s)):
        t = s[:i] + s[i+1:]
        if t == t[::-1]:
            if i <= len(s) // 2:
                print(s[:len(s)-i] + s[i] + s[len(s)-i:])
            else:
                print(s[:len(s)-i-1] + s[i] + s[len(s)-i-1:])
            return
    print('NA')
    return

if __name__ == '__main__':
    main()
