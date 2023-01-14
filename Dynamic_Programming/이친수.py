n = int(input())

oneEnd = [0] * (n+1)

zeroEnd = [0] * (n+1)

oneEnd[1] = 1

for i in range(2, n+1):
    oneEnd[i] = zeroEnd[i-1]
    zeroEnd[i] = oneEnd[i-1] + zeroEnd[i-1]

print(oneEnd[n] + zeroEnd[n])
