from sys import stdin
h=int(stdin.readline())
w=int(stdin.readline())
num=int(stdin.readline())
graph=[]
for i in range(h*w):
    graph.append("B")
for o in range(num):
    input=[z for z in stdin.readline().split()]
    if input[0]=="R":
        for a in range(w):
            v=graph[(int(input[1])-1)*w+a]
            if v=="G":
                graph[(int(input[1])-1)*w+a]="B"
            if v=="B":
                graph[(int(input[1])-1)*w+a]="G"
            
    if input[0]=="C":
        for b in range(h):
            n=graph[(int(input[1])-1)+b*w]
            
            if n=="G":
                graph[(int(input[1])-1)+b*w]="B"
                
            if n=="B":
                graph[(int(input[1])-1)+b*w]="G"
              
            
print(graph.count("G"))