def dfs(k, n, r, a):
    if k > r:

        print("".join(f"{a[i]:>3}" for i in range(1, r + 1)))
        return

    for i in range(a[k - 1] + 1, n + 1):
        a[k] = i
        dfs(k + 1, n, r, a)


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()

    n = int(data[0])
    r = int(data[1])


    a = [0] * (n + 1)

    dfs(1, n, r, a)


if __name__ == "__main__":
    main()
