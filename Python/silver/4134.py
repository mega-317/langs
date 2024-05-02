def A(a):
    i = 2
    while i*i <= a:
        if a % i == 0:
            return False
        i += 1
    return True

a = int(input())
for i in range(a):
    b = int(input())
    c = b
    if c == 0 or c == 1:
        print(2)
        continue
    while A(c) != True:
        c += 1
    print(c)
    