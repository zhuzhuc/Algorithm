def find_combinations(n, idx=0, current_sum=0, combination=None):
    if combination is None:
        combination = []
    
    if idx == 10:
        if current_sum == n:
            result.append(combination[:])
        return
    
    for i in range(1, 4):
        if current_sum + i <= n:
            combination.append(i)
            find_combinations(n, idx + 1, current_sum + i, combination)
            combination.pop()

def roasted_chicken(n):
    global result
    result = []
    find_combinations(n)
    
    print(len(result))
    for combo in result:
        print(' '.join(map(str, combo)))

# Read input
n = int(input())
roasted_chicken(n)
