from itertools import combinations
import sys
import math


def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    k = int(data[1])
    nums = list(map(int, data[2:n + 2]))

   
    PR = 0
    for combo in combinations(nums, k):
        s = sum(combo)
        if is_prime(s):
            PR += 1

   
    print(PR)


if __name__ == "__main__":
    main()