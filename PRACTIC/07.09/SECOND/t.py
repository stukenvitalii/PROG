# put your python code here
a = int(input())
n = int(input())
s=''
if a>=0:
    while a%2 >=0 and a>1:
        s+= str(a%2)
        a//=2
    s=str((n-len(str(a)+s))*"0"+str(a)+s[::-1])[-n:]
else:
    a= abs(a) - 1
    while a % 2 >= 0and a>1:
        s += str(a%2)
        a //=2
    s=str((n-len(str(a)+s))*"0"+str(a)+s[::-1])[-n:]
    for i in range(len(s)):
        if s[i] =="0":
            s=s[:-n+i]+"1"+s[-n+1+i:]
        elif s[i] == "1":
            s=s[:-n+i]+"0"+s[-n+1+i:]
    s=s[:n]
print(s)

a.rjust



