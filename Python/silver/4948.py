def PrimeNum(n):
    i = 2
    while i*i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

while True:
    a = int(input())
    
    if a == 0:
        break
    
    b = 2 * a
    
    i = a + 1
    count = 0
    while i <= b:
        if PrimeNum(i):
            count += 1
        i += 1
    print(count)