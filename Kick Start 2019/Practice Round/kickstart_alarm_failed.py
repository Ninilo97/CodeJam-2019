import time

if __name__ == "__main__":    
    t = int(input())
    for case in range(t):
        n, k, x1, y1, c, d, e1, e2, f = [int(num) for num in input().split()]
        start = time.time()
        a = []
        a.append((x1+y1)%f)
        for _ in range(1,n):
            x = (c*x1+d*y1+e1)%f
            y = (d*x1+c*y1+e2)%f
            a.append((x+y)%f)
            x1, y1 = x, y
        total = []
        POWER = 1000000007
        func = lambda temp,i,j,k: temp*((j+1)**(k))%POWER
        for i in range(n):
            temp=(n-i)*a[i]%POWER
            for j in range(i+1):
                for kk in range(1,k+1):
                    total.append(func(temp,i,j,kk))
        print("Case #{}: {}".format(case+1,sum(total)%POWER))
        end = time.time()
        print(end-start)

"""
        def power(i,num,ele_at_ai,k):
        bs = [j+1 for j in range(i+1)]
        pwr = [j for j in range(1,k)]
        bs_pwr = [j**k for j in bs for k in pwr]*(n-i)
        return sum([ele_at_ai*i for i in bs_pwr])%POWER
        total = []
        #+NBnb=
        total = sum([power(i,n,a[i],k+1) for i in range(n)])
        print("Case #{}: {}".format(case+1,total%POWER))
        
        func = lambda temp,i,j,k: temp*((j+1)**(k))%POWER
        for i in range(n):
            temp=(n-i)*a[i]%POWER
            for j in range(i+1):
                for kk in range(1,k+1):
                    total.append(func(temp,i,j,kk))
                    #total += (n-i)*a[i]*((j+1)**(kk))
        print("Case #{}: {}".format(case+1,sum(total)%POWER))
        
        la = k
        ans = 0
        for i in range(1,n+1):
            ans=(ans+la*(n+2-i)%POWER*a[i-1]%POWER)%POWER
            x=((i**(k+1))-1)*(((i-1)**POWER)-2)%POWER
            x=x-1
            if(x<0):
                x+=POWER
            la+=x
            la%=POWER
        print("Case #{}: {}".format(case+1,ans))

def process_total(a,i):
    total = 0
    temp=(n-i)*a[i]%POWER
    for j in range(i+1):
        for kk in range(1,k+1):
            total += temp*((j+1)**(kk))
    #nb=+NB
    return total % POWER
    #print("Case #{}: {}".format(case+1,[process_total(a,i) for i in range(n)]))
"""
