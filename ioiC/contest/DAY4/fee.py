d = [1,1]
for i in range(2,500):
    d.append((d[i-1]+d[i-2])%(1e9+7))
for idx,num in enumerate(d) :
    print(idx,num)