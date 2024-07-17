import sys
import math


def factorial(n):
    return math.factorial(n)


def permutation_to_index(perm):
    n = len(perm)
    pos = 0
    factor = factorial(n - 1)
    used = [False] * (n + 1)

    for i in range(n):
        count = 0
        for j in range(1, perm[i]):
            if not used[j]:
                count += 1
        pos += count * factor
        if i < n - 1:
            factor //= (n - 1 - i)
        used[perm[i]] = True

    return pos + 1


def index_to_permutation(n, index):
    perm = []
    used = [False] * (n + 1)
    index -= 1
    factor = factorial(n - 1)

    for i in range(n):
        count = index // factor
        index %= factor
        for j in range(1, n + 1):
            if not used[j]:
                if count == 0:
                    perm.append(j)
                    used[j] = True
                    break
                count -= 1
        if i < n - 1:
            factor //= (n - 1 - i)

    return perm


def main():
    input = sys.stdin.read
    data = input().strip().split()

    N = int(data[0])
    M = int(data[1])
    perm = list(map(int, data[2:2 + N]))

    current_index = permutation_to_index(perm)
    new_index = current_index + M
    new_perm = index_to_permutation(N, new_index)

    print(" ".join(map(str, new_perm)))


if __name__ == "__main__":
    main()
