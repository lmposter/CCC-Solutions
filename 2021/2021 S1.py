from sys import stdin
num=int(stdin.readline())
totalarea=0
h=[int(x) for x in stdin.readline().split()]
w=[int(y) for y in stdin.readline().split()]
for i in range(num):
    totalarea+=((h[i]+h[i+1])*w[i])/2
print(totalarea)