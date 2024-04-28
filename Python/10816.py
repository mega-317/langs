a = int(input())
# 배열의 인덱스를 활용해보자
arrPlus = [0]*10000001
arrMinus = [0]*10000001

list1 = list(map(int, input().split()))
for i in range(len(list1)):
    if list1[i] >= 0:
        arrPlus[list1[i]] += 1
    else:
        arrMinus[-list1[i]] += 1

b = int(input())
list2 = list(map(int, input().split()))
for i in range(len(list2)):
    if list2[i] >= 0:
        print(arrPlus[list2[i]], end=' ')
    else:
        print(arrMinus[-list2[i]], end=' ')