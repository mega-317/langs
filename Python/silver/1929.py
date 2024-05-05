def primeNum(a):
    i = 2
    while i * i <= a:
        if a % i == 0:
            return False
        i += 1
    return True

a, b = map(int, input().split())

i = a
while i <= b:
    if i == 1:
        i += 1
        continue
        
    if primeNum(i):
        print(i)
    i += 1