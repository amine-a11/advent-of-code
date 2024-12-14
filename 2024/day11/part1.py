l = list(map(int,open("in.txt","r").readline().split()))

for _ in range(25):
    newl=[]
    for i in l:
        s=str(i)
        if i==0:newl.append(1)
        elif len(s)%2==0:
            newl.append(int(s[:len(s)//2]))
            newl.append(int(s[len(s)//2:]))
        else:
            newl.append(i*2024)
    l=newl
    
print(len(l))