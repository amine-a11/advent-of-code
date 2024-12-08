lines = open("in.txt","r").readlines()

def check(l,target):
    n=len(l)-1

    for i in range(1<<n):
        s = bin(i)[2:].zfill(n)
        somme=l[0]
        for j in range(1,len(l)):
            if s[j-1]=='0':
                somme+=l[j]
            else:
                somme*=l[j]
        if somme==target:
            return True

    return False

ans=0
for line in lines:
    target,*nums = map(int,line.replace(":","").split())
    if check(nums,target):
        ans+=target
print(ans)