'''
def back(x, n):
    x = [-1]
    while len(x) > 0:
        chosen = False

        while not chosen and x[len(x) - 1] < n - 1:
            x[len(x) - 1] += 1
            chosen = consistent(x)

        if chosen:
            if solution(x, n):
                # found a solution
                print(x)
            else:
                x.append(-1)
        else:
            x = x[:-1]

def consistent(x):
    for i in range(len(x) - 1):
        if x[i] == x[len(x) - 1]:
            return False

    return True

def solution(x, n):
    return len(x) == n

back([], 3)
'''

def print_it(sol, n):
    print(sol[1:])
    return

def succesor(n, k, sol):
    if sol[k] < 9 :
        sol[k] = sol[k] + 1;
        return True
    return False

def is_valid(k, sol):
    if len(sol) < 2:
        return False
    if sol[1] == 0 : return False
    x = k // 2 + 1
    for j in range (1, x):
        y = k - j + 1
        for i in range (1, y):
            a = i
            b = i + j
            c = i + j
            d = i + j + j
            if sol[a:b] == sol[c:d] : return False
    return True

def is_solution(k, n):
    return (k == n + 1)

def back(x, n):
    x = [0, -1]
    while len(x) > 0:
        chosen = False

        while not chosen and x[len(x) - 1] < 10 - 1:
            x[len(x) - 1] += 1
            chosen = is_valid(len(x), x)

        if chosen:
            if is_solution(len(x), n):
                # found a solution
                print_it(x, len(x))
            else:
                x.append(-1)
        else:
            x = x[:-1]

def main():
    sol = []
    n = int(input('n='))
    for i in range(n + 1): sol.append(i);
    back(sol, n)

main()
