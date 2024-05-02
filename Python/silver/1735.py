def A(a, b):
    while b > 0:
        [a, b] = [b, a % b]
    return a 

a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())

if b1 > b2:
    res = (b1 * b2) / A(b1, b2)
else:
    res = (b1 * b2) / A(b2, b1)
res = int(res)

a1 = int((res / b1) * a1)
a2 = int((res / b2) * a2)

result1 = a1 + a2

if result1 > res:
    c = A(result1, res)
else:
    c = A(res, result1)

result1 = int(result1 / A(c, res))
res = int(res / A(c, res))
    
print(result1, res)