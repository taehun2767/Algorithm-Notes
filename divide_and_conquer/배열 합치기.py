import sys

n, m = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

ia = 0
ib = 0
for i in range(n+m):
  if ia == n:
    print(B[ib], end=" ")
    ib += 1
  elif ib == m:
    print(A[ia], end=" ")
    ia += 1
  else:
    if A[ia] > B[ib]:
      print(B[ib], end=" ")
      ib += 1
    else:
      print(A[ia], end=" ")
      ia += 1