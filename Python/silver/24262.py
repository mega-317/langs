n, m = map(int, input().split())
input = list(map(int, input().split()))
    
sum = 0

i = 0
while i < n-2:
    j = i+1
    while j < n-1:
        k = j+1
        while k < n:
            if sum < (input[i] + input[j] + input[k]) and (input[i] + input[j] + input[k]) <= m:
                sum = input[i] + input[j] + input[k]
            k += 1
        j += 1
    i += 1
                
print(sum)