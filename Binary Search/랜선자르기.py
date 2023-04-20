k, n = map(int, input().split())
lst = []

for i in range(k):
    lst.append(int(input()))

left = 1
right = sum(lst) // n

# 이분 탐색
while left <= right:
    mid = (left+right)//2
    count = sum([ele // mid for ele in lst])
    # n이상의 랜선을 만들 수 있을 경우 최대 길이만큼 더 optimize가능함
    if count >= n:
        left = mid+1
    # n미만의 랜선을 만드는 경우 길이를 줄여서 개수 조건을 충족해야함
    else:
        right = mid -1

    
print(right)
