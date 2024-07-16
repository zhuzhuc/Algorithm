from itertools import permutations

def solve(A, B, C):
    digits = '123456789'
    results = []


    for perm in permutations(digits):
        x = int(''.join(perm[0:3]))
        y = int(''.join(perm[3:6]))
        z = int(''.join(perm[6:9]))

        if x * B == y * A and y * C == z * B:
            results.append((x, y, z))

    if results:
        results.sort()
        for result in results:
            print(result[0], result[1], result[2])
    else:
        print('No!!!')

A, B, C = map(int, input().split()
solve(A, B, C)
