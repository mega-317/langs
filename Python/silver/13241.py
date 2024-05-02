def A(a, b):
    while b != 0:
        [a ,b] = [b, a%b]
    return a

a, b = map(int, input().split())
if a > b:
    aa = A(a, b)
else:
    aa = A(b, a)

result = (a * b) / aa
print(int(result))