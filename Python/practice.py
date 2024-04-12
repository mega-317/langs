a = int(input())

b = list(map(int, input().split()))

count = 0

for i in range(a):
    prime = 0
    j = 2
    if b[i] < 2:
        continue
    
    while True:
        if(j*j > b[i]):
            break
        
        if b[i] % j == 0:
            prime = 1
            break
        j += 1
        
        
    if prime == 0:
        count += 1
        
print(count)