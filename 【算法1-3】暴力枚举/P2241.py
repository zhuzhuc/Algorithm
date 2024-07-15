def count(n, m):
    squares = sum((n - i) * (m - i) for i in range(min(n, m)))
    rectangles = (n * (n + 1) // 2) * (m * (m + 1) // 2) - squares

    return squares, rectangles

n,m = map(int,input().split())
squares, rectangles = count(n,m)

print(squares, rectangles)
