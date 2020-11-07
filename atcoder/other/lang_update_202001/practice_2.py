import string

cnt = 0


def merge_sort(left, right, A):
    # sort [left, right)
    if left + 1 == right:
        return [A[left]]
    mid = (left + right) >> 1
    l_arr = merge_sort(left, mid, A)
    r_arr = merge_sort(mid, right, A)

    ret = []
    while l_arr and r_arr:
        print(f"? {l_arr[0]} {r_arr[0]}", flush=True)
        ans = input()
        if ans == "<":
            ret.append(l_arr.pop(0))
        else:
            ret.append(r_arr.pop(0))
    if l_arr:
        ret.extend(l_arr)
    if r_arr:
        ret.extend(r_arr)
    return ret


def solve26(N) -> None:
    A = list(string.ascii_uppercase)[:N]
    ans = merge_sort(0, N, A)
    print(f"! {''.join(ans)}", flush=True)


def main() -> None:
    N, _ = map(int, input().split())
    if N != 5:
        solve26(N)


if __name__ == '__main__':
    main()
