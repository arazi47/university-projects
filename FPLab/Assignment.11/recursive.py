'''
def back(x, n):
    x.append(0)

    for i in range(n):
        x[len(x) - 1] = i

        if consistent(x):
            if solution(x, n):
                # found a solution
                print(x)
            else:
                back(x[:], n)

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

def bcktr(n, k, sol):
    if is_solution(k, n):
        print_it(sol, n)
    else :
        sol[k] = -1
        while succesor(n, k, sol) :
            if is_valid(k, sol) : bcktr(n, k + 1, sol)

def main():
    sol = []
    n = int(input('n='))
    for i in range(n + 1): sol.append(i);
    bcktr(n, 1, sol)

main()
