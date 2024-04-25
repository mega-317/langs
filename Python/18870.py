a = int(input())
arr = list(map(int, input().split()))

arrSort = sorted(set(arr))
        
index_dict = {num: idx for idx, num in enumerate(sorted(set(arr)))}

# 각 숫자의 인덱스를 출력
for num in arr:
    print(index_dict[num], end=" ")
