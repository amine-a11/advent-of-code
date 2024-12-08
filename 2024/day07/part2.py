
lines = open("in.txt","r").readlines()

ans=0

def go(val,ind,N,target,nums):
    if val>target:return False
    if ind == N:
        if val==target:
            return True
        return False
    return go(val+nums[ind],ind+1,N,target,nums) or go(val*nums[ind],ind+1,N,target,nums) or go(int(str(val)+str(nums[ind])),ind+1,N,target,nums)

for line in lines:
    target,*nums = map(int,line.replace(":","").split())
    if go(nums[0],1,len(nums),target,nums):
        ans+=target

print(ans)
