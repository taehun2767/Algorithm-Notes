n = int(input())

graph = [[' '] * n for _ in range(n)]

baseStars = ["***", "* *", "***"]

def printingStars(x, y, n):
  if n == 3:
    for i in range(n):
      for j in range(n):
        graph[x+i][y+j] = "*"
    graph[x+1][y+1] = " "
  else:
    rn = n//3
    printingStars(x, y, rn)
    printingStars(x, y+rn, rn)
    printingStars(x, y+2*rn, rn)
    printingStars(x+rn, y, rn)
    printingStars(x+rn, y+2*rn, rn)
    printingStars(x+2*rn, y, rn)
    printingStars(x+2*rn, y + rn, rn)
    printingStars(x+2*rn, y+2*rn, rn)

printingStars(0, 0, n)

print(graph)

for ele in graph:
  print("".join(ele))