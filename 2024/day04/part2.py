M = [*map(lambda x: x[:-1] if x[-1]=='\n' else x,open('in.txt','r').readlines())]
def ok(g):
    S1=g[0][0]+g[1][1]+g[2][2]
    S2=g[0][2]+g[1][1]+g[2][0]
    ok1 = S1 == 'MAS' or S1 == 'SAM'
    ok2 = S2 == 'MAS' or S2 == 'SAM'
    return ok1 and ok2
ans=0
for i in range(len(M)-2):
    for j in range(len(M[0])-2):
        subM=[]
        for k in range(i,i+3):
            subM.append(M[k][j:j+3])
        ans+=int(ok(subM))
print(ans)
        
