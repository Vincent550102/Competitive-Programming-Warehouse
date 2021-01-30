import math
pre = 0
# pree = 0
for n in range(1,50):
    anssum = 0
    for i in range(1,n+1):
        num = 0
        for j in range(2,i+1):
            num+=math.floor(math.log(i,j))
        anssum += num
    print("n=",n, anssum, anssum-pre)
    pre = anssum