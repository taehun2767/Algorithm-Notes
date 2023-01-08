height = int(input())

blocks = []

for _ in range(height):
  block = input()
  blocks.append(block)

def quadTree(x, y, n):

  ans = ""
  zero = False
  one = False
  if n == 1:
    return blocks[x][y]
  
  for i in range(n):
      for j in range(n):
        if one and zero:
          break
        if blocks[x+i][y+j] == "0":
          zero = True
        elif blocks[x+i][y+j] == "1":
          one = True
    
  if one and zero:
    half = n // 2
    ans += "("
    ans += quadTree(x, y, half)
    ans += quadTree(x, y+half, half)
    ans += quadTree(x+half, y, half)
    ans += quadTree(x+half, y+half, half)
    ans += ")"
  
  elif one :
    return "1"
  elif zero:
    return "0"
  
  return ans

print(quadTree(0, 0, height))