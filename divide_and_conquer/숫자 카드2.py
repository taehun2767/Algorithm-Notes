import sys

N = int(input())
nList = sorted(map(int, sys.stdin.readline().split()))
M = int(input())
mList = map(int, sys.stdin.readline().split())


def binary_search(arr, target, start, end):
  while start <= end:
    mid = (start +end)//2
    if arr[mid] == target:
      count = 1
      idx = mid + 1
      while idx <=len(arr)-1 and arr[mid] == arr[idx]:
        count += 1
        idx +=1
      idx = mid - 1
      while idx >= 0 and arr[mid] == arr[idx]:
        count += 1
        idx -=1
      return count
    elif arr[mid] < target:
      start = mid +1
    elif arr[mid] > target:
      end = mid - 1
  return 0


n_dict = {}
for ele in nList:
  if ele not in n_dict:
    n_dict[ele] = binary_search(nList, ele, 0, N-1)

print(" ".join(str(n_dict[x]) if x in n_dict else '0' for x in mList))
