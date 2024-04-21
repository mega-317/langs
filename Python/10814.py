class member:
    def __init__(self, age, name):
        self.age = age
        self.name = name
    

a = int(input())
m = []
for i in range(a):
    age, name = input().split()
    m1 = member(int(age), name)
    m.append(m1)

# 나이를 기준으로 정렬
sorted_members = sorted(m, key=lambda x: x.age)
# lambda를 통해 각각의 요소에 접근할 수 있음
for i in range(len(sorted_members)):
    print(sorted_members[i].age, sorted_members[i].name)