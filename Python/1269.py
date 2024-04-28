a, b = map(int, input().split())
aa1 = list(map(int, input().split()))
bb1 = list(map(int, input().split()))
aa = set(aa1)
bb = set(bb1)
result1 = aa - bb
result2 = bb - aa
print(len(result1) + len(result2))