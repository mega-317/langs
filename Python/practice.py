
while True:
    a = int(input())
    
    if a == -1:
        break

    array = []

    for i in range(a - 1):
        if a % (i+1) == 0:
            array.append(i+1)
            
    c = sum(array)
    if c != a:
        print(f"{a} is NOT perfect.")
        continue
        
    print(f"{a} =", end=' ')
    print(array[0], end='')
    
    for i in range(len(array)-1):
        print(" + ", end='')
        print(array[i+1], end='')
    print(' ')