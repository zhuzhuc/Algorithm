import itertools


def main():
    import sys
    input = sys.stdin.read

    n = int(input().strip())

    a = list(range(1, n + 1))

    permutations = itertools.permutations(a)


    for perm in permutations:
        formatted_perm = "".join(f"{num:5}" for num in perm)
        print(formatted_perm)


if __name__ == "__main__":
    main()
