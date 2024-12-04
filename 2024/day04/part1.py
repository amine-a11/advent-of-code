M = [*map(lambda x: x[:-1] if x[-1]=='\n' else x,open('in.txt','r').readlines())]
def countXMAS_D(g):
    s=''
    ss=''
    for i in range(len(g)):
        s+=g[i][i]
        ss+=g[i][3-i]
    return int(s=='XMAS') + int(s[::-1]=='XMAS') + int(ss=='XMAS') + int(ss[::-1]=='XMAS')
def countXMAS_I(g):
    gg = [''.join(i)for i in [*zip(*g)]]
    ans=0
    for i in range(len(g)):
        ans+=gg[i].count("XMAS")
        ans+=gg[i].count("SAMX")
    return ans    

def countXMAS(g):    
    ans=0
    for i in range(len(g)):
        ans+=g[i].count("XMAS")
        ans+=g[i].count("SAMX")
    return ans    

ans=countXMAS_I(M)+countXMAS(M)

for i in range(len(M)):
    for j in range(len(M[0])):
        if i+3<len(M) and j+3<len(M[0]):
            subM=[]
            for k in range(i,i+4):
                subM.append(M[k][j:j+4])
            ans += countXMAS_D(subM)

print(ans)
