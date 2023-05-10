n = int(input())

board = [[0] * n for _ in range(n)]

def backtracking(n, r, c, queenList, count):

  if count == n:
    return 1
  if count <  r:
    return 0
  if r > n-1 or c > n-1:
    return 0
  
  ret = 0
  
  impossible = False

  for i in range(count):
    if queenList[i][0] == r or queenList[i][1] == c or abs(queenList[i][1]-c) == abs(queenList[i][0]-r):
      impossible = True
      break


  if not impossible:
    queenList.append([r, c])
    if c+1 > n-1:
      ret +=  backtracking(n , r+1, 0, queenList, count + 1)  
    else:
      ret += backtracking(n , r, c+1, queenList, count + 1)
    queenList.pop()
  if c+1 > n-1:
    ret +=  backtracking(n , r+1, 0, queenList, count)  
  else:
    ret += backtracking(n , r, c+1, queenList, count)

  return ret

queenList = []
count = 0
ans = backtracking(n, 0, 0 , queenList, count)
print(ans)
