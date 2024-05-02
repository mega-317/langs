a = int(input())
sum = 0
sum1 = 0
arr = []
count = 0
count1 = 0
while sum <= a:
    sum1 = sum
    count1 = count
    
    while sum1 < a:
        count1 += 1
        sum1 += 3
    if sum1 == a:
        arr.append(count1)
    sum += 5
    count += 1

if len(arr) == 0:
    print(-1)
else:
    print(min(arr))