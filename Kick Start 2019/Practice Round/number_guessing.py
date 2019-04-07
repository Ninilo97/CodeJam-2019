#nb=+NB
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a, b = map(int,input().split())
        n = int(input())
        for _ in range(n):
            temp = int(a+1+(b-(a+1))/2)
            print(temp)
            rsp = str(input())
            if rsp=="TOO_SMALL":
                a = temp
            elif rsp=="TOO_BIG":
                b = temp
            elif rsp=="CORRECT":
                break
