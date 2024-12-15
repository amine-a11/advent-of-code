import re
import math
f = open("in.txt","r").read().split("\n\n")
ans=0
for i in f:
    A,B,P=i.split('\n')
    AX,AY=map(int,re.findall("\d+",A))
    BX,BY=map(int,re.findall("\d+",B))
    PX,PY=map(int,re.findall("\d+",P))
    x=(PX*BY-PY*BX)/(AX*BY-AY*BX)
    y=(PX-AX*x)/BX
    if x%1==0 and y%1==0:
        ans+=int(3*x+y)
print(ans)

