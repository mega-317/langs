a = int(input())

for i in range(a):
    b = input()
    res = 1
    open = 0
    for j in range(len(b)):
        if b[j] == '(':
            open += 1
        elif b[j] == ')':
            if open <= 0:
                res = 0
            else:
                open -= 1
    if open != 0:
        res = 0
    if res == 1:
        print("YES")
    else:
        print("NO")

