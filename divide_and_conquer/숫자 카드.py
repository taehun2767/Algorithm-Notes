N = int(input())
nList = list(map(int, input().split()))
M = int(input())
mList = list(map(int, input().split()))

_dict = {}

for ele in nList:
  _dict[ele] = 0
  
for e in mList:
  if e in _dict:
    print("1", end=" ")
  else:
    print("0", end=" ")

# answer = ["1" if ele in nList else "0" for ele in mList ]
# print(" ".join(answer))