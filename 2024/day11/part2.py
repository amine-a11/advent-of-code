l = list(map(int,open("in.txt","r").readline().split()))
m = dict()
for i in l:
    try:m[i]+=1
    except:m[i]=1
for _ in range(75):
    newm=dict()
    for i in m.keys():
        s=str(i)
        if i==0:
            try:newm[1]+=m[0]
            except:newm[1]=m[0]
        elif len(s)%2==0:
            x = int(s[:len(s)//2])
            y = int(s[len(s)//2:])
            try:newm[x]+=m[i]
            except:newm[x]=m[i]
            try:newm[y]+=m[i]
            except:newm[y]=m[i]
        else:
            try:newm[i*2024]+=m[i]
            except:newm[i*2024]=m[i]

    m=newm
    
ans=0
for i in m.keys():
    ans+=m[i]
print(ans)