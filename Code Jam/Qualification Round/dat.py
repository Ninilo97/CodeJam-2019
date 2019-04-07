import math
import sys

a = [[1 for i in range(1025)] for j in range(11)]
def prep():
    for i in range(10):
        for j in range(1024):
            a[i+1][j+1]=1
    x=0
    tm=1025
    #+NBnb=
    for i in range(10):
        tm=int(tm/2)
        x=1
        for j in range(2**(i)):
            for k in range(x,tm+x):
                a[i+1][k]=0
            x+=tm+tm
    #+NBnb=
    #for i in range(10):
        #print(a[i+1][1:1025])

if __name__ == "__main__":
  prep()
  t=int(input())
  for cse in range(t):
    #+NBnb=
    n,b,f = [int(num) for num in input().split()]
    full_list = [int(i) for i in range(n)]
    sz=0
    res = []
    #+NBnb=
    for i in range(11-int(math.ceil(math.log2(n))),11):
        #print(math.log2(n)," ",math.ceil(math.log2(n))," ",int(math.ceil(math.log2(n))))
        #print(i," ",n+1)
        sys.stdout.flush()
        print(*a[i][1:n+1],sep='')
        #print(a[i][1:n+1])
        res.append(input())
        sz+=1
    #+NBnb=
    #print(res[:])
    for i in range(0,n-b):
        tmm = ''.join([j[i] for j in res])
        full_list.remove(int(tmm,2))
    #print("Case #{}:".format(cse),end=' ')
    print(*full_list,sep=' ')
    cde = int(input())
    if(cde): continue
    break
