height = int(input())


stars = ["  *  ", " * * ", "*****"]

def printStars(height, stars):
    count = 1
    while height != 3:
        for j in range(len(stars)):
            tempStr = stars[j] + " " * ((count-1) *6 +1 -6*(j//3))  + stars[j]
            stars.append(tempStr)
        height //= 2
        count *= 2

    for i in range(len(stars)):
        print(" " *(len(stars)-(i//3+1)*3), end="")
        print(stars[i], end="")
        print(" " *(len(stars)-(i//3+1)*3))


printStars(height, stars)