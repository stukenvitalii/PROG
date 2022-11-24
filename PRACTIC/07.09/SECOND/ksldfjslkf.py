a = list(map(int,input().split()))

x = int(input())
k = 0
i = 0

while i < len(a):
    
    if a[i] == x:
        k = 1
    i += 1
    
print("YES" if k == 1 else "NO")

    

