a = int(input())
b = int(input())
prime = []
i = a
while i <= b:
    if i >= 2:
        j = 2
        p = 0
        while True:
            if(j*j > i):
                break
            if i % j == 0:
                p = 1
                break
            j += 1
        
        if p == 0:
            prime.append(i)
    
    i += 1
    
if len(prime) == 0:
    print(-1)
else:
    print(sum(prime))
    print(min(prime))