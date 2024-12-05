lines=open('in.txt','r').readlines()


rules = set()
prods = []
r=True
for line in lines:
    if line == '\n':
        r=False
        continue
    if r:
        rules.add(line.rstrip('\n'))
    else:
        prods.append(line.rstrip('\n').split(','))

def ok(l):
    oo=False
    for i in range(len(l)):
        for j in range(i+1,len(l)):
            if l[i]+'|'+l[j] not in rules:
                oo=True
                if l[j]+'|'+l[i] in rules:
                    l[i],l[j] = l[j],l[i]
            # print(l[i],l[j])
    return oo
    
ans=0
for prod in prods:
    if ok(prod):
        ans+=int(prod[len(prod)//2])
print(ans)